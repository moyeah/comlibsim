//************************************************************************
// Copyright (C) 2012 Jorge Estrela da Silva
//
// 
//************************************************************************

//For a system of dimension n, generates a text file (traj.txt) with the following columns:
//1 - time
//2 - first state variable
//(...)
//n+2 - accumulated cost
//n+3 - computed control
//n+4 - disturbance
//n+5 - only relevant if delta_a \neq delta_b

// To load on Matlab and, e.g., plot the projection of the trajectory on the x_1--x_2 plane:
//>> load traj.txt
//>> plot(traj(:,2),traj(:,3))
//To plot the accumulated cost:
//>> plot(traj(:,1),traj(:,5)) 

#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>

#include <fpu_control.h>

//#define USE_VF 1
#ifdef USE_VF
#include "VFComputeMR.hpp"

void configureVF(VF &);
#endif

#include "ode_solvers.hpp"

#include "../parser.hpp"
#include "../comlibsim.hpp"

int dynamics(double t, const double *x0, double *deriv, void *param);

void compute_control(const double *state, double * const input);

using namespace ComLibSim;
Cluster* init_cluster();

int sim_main(const struct arguments *arguments) {
  double a, b;
  int i=0;
  double t = 0;
  unsigned int mr_count=0;
  rk_data_t rk_data;  
  int control_div_max;
  int control_div=0;
  double delta_t_control;
  double delta_t;
  double *state;
  unsigned int horizon_MR=1;
  int n_dim;
  
  fpu_control_t cw;
  _FPU_GETCW(cw);
  cw &= ~_FPU_EXTENDED;
  cw |= _FPU_DOUBLE;
  _FPU_SETCW(cw);

  Cluster *c0 = init_cluster();

  Parser parser (arguments->cluster_xml_file[0]);

  parser.to_cluster (*c0);

  std::ofstream sensors_map (arguments->sensors_map_file);
  c0->write_map (sensors_map);

#ifdef USE_VF  
  char undef;    
  unsigned int i_a=0;  
  double sc;
  double sc_total=0;
  VFComputeMR vf(horizon_MR);  
  
  
  configureVF(vf);
  vf.integrate = rkIntegrate;  
  //vf.integrate = eulerIntegrate;
  vf.setSavePolicyMode(true);
  vf.setFileName("");
  vf.setup2sim();
  vf.setNumThreads(1);

  
  int res=vf.loadRO("data/vf.dat");          
  if(res==-1)
  {
    perror("vf.loadRO");
    exit(1);
  }

  n_dim = vf.getNDimensions()+1;
  rkInit(&rk_data, n_dim, 2+vf.getNLGains());    
  state = (double *) malloc(sizeof(double)*n_dim);

  control_div_max=std::max(1.0,vf.m_delta/arguments->step_size/horizon_MR);
  delta_t_control = vf.m_delta/horizon_MR;
  delta_t = delta_t_control/control_div_max;

#else
  
  //3 + número de se sensores
  n_dim = 3 + c0->nb_sensors();
  
  rkInit(&rk_data, n_dim, 2);      
  state = (double *) malloc(sizeof(double)*n_dim);

  control_div_max=1;
  delta_t_control = arguments->step_size;
  delta_t = arguments->step_size;
#endif
 
  //initial posture
  state[0] = 0;
  state[1] = 0;  
  state[2] = 0;
  c0->get_data(state+3);    

  //output filename
  std::ofstream simulation_log (arguments->simulation_log_file);
  simulation_log << std::fixed << std::setprecision (10);
 
  if (arguments->verbose == 1) 
    printf("%d %f %f\n",control_div_max, delta_t_control, delta_t);
  printf("n_dim=%u; horizon_MR=%u\n",n_dim,horizon_MR);  

  // Log simulation files
  std::ofstream accumulator_log (arguments->accumulator_log_file);
  accumulator_log << std::fixed << std::setprecision (10);
  std::ofstream rate_log (arguments->rate_log_file);
  rate_log << std::fixed << std::setprecision (10);
  c0->write_tag (rate_log);
    
  //constant disturbance
  b=0.25;
  while(t < arguments->sim_time)  
  {
    c0->init_int();
    
    //b=0.2+0.05*sin(t);

    if(control_div==0)
    {
      control_div=control_div_max;
      if(mr_count==0)
      {
        mr_count=horizon_MR;
#ifdef USE_VF
        vf.getActA_SC(state, &a, &i_a, &undef, i_a,&sc);
        sc_total+=sc;
#else        
        compute_control(state,rk_data.aux.input);
#endif        
      }
      //uncomment this to use computed disturbance
      //vf.getActB(delta_t_control, state, (void *) &rk_data, mr_count, i_a, &b);    
      --mr_count;
    }
    --control_div;
    
#ifdef USE_VF    
    rk_data.aux.input[0] = a;
    rk_data.aux.input[1] = b;
#else
    a = rk_data.aux.input[0];
    b = rk_data.aux.input[1];
#endif

    simulation_log << t << " ";
//    sprintf(buf,"%f ",t);
    for(i=0;i<n_dim;++i)
      simulation_log << state[i] << " ";
//      sprintf(buf+strlen(buf),"%f ",state[i]);

    simulation_log << a << " " << b << std::endl;
//    sprintf(buf+strlen(buf),"%f %f\n",a,b);

    if (arguments->verbose == 1)
    {
      std::cout << t << " ";
      for(i=0;i<n_dim;++i)
        std::cout << state[i] << " ";
      simulation_log << a << " " << b << std::endl;
    }
//      printf("%s",buf);
//    fprintf(fp,"%s",buf);

  // Log simulation
  c0->write_accumulator_log_ln (t, accumulator_log);
  c0->write_rate_log_ln (t, rate_log);

    rkIntegrate(&rk_data, delta_t, state, rk_data.aux.input, dynamics);
  c0->set_data(state+3, arguments->step_size);
//  c0->set_rate();
    
    t += delta_t;

#ifdef USE_VF
    if(vf.insideComputationalDomain(state)==false)
      break;
#endif      
  } 

#ifdef USE_VF
  vf.unload();
  printf("n_dim=%u; horizon_MR=%u, total_sw_cost=%f\n",vf.getNDimensions(),horizon_MR,sc_total);
#endif  
//  fclose(fp);
  
  return c0->nb_sensors ();
}



