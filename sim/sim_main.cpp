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



//interval between samples of the generated series
#define STEP_SIZE 0.1

//xml filepath
#define CLUSTER_CONF "config/cluster.xml"

//log files
#define SIM_LOG "log/sim.log" //Simulation
#define XML_LOG "log/xml.log" //XML import

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

#include "../cluster.hpp"
#include "../parser.hpp"

int dynamics(double t, const double *x0, double *deriv, void *param);

void compute_control(const double *state, double * const input);

using namespace ComLibSim;
Cluster* init_cluster();

int main(int argc, char *argv[]) {
  double a, b;
  int i=0;
  char buf[1000];
  FILE *fp;
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

/* Test parser */
  Parser parser (CLUSTER_CONF);

  std::ofstream log (XML_LOG);

  parser.to_cluster (*c0, log);

  c0->write ();

/* END Test parser*/

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

  control_div_max=std::max(1.0,vf.m_delta/STEP_SIZE/horizon_MR);
  delta_t_control = vf.m_delta/horizon_MR;
  delta_t = delta_t_control/control_div_max;

#else
  
  //4 + número de se sensores
  n_dim = 4 + c0->nb_sensors();
  
  rkInit(&rk_data, n_dim, 2);      
  state = (double *) malloc(sizeof(double)*n_dim);

  control_div_max=1;
  delta_t_control = STEP_SIZE;
  delta_t = STEP_SIZE;
#endif
 
  //initial posture
  state[0] = 0;
  state[1] = 0;  
  state[2] = 0;
  c0->get_data(state+3);    

  //output filename
  fp = fopen(SIM_LOG,"w"); 
  
  printf("%d %f %f\n",control_div_max, delta_t_control, delta_t);
  printf("n_dim=%u; horizon_MR=%u\n",n_dim,horizon_MR);  
    
  //constant disturbance
  b=0.25;
  while(t<600)  
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

    sprintf(buf,"%f ",t);
    for(i=0;i<n_dim;++i)
      sprintf(buf+strlen(buf),"%f ",state[i]);


    sprintf(buf+strlen(buf),"%f %f\n",a,b);

    printf("%s",buf);
    fprintf(fp,"%s",buf);
    
    

    rkIntegrate(&rk_data, delta_t, state, rk_data.aux.input, dynamics);
    c0->set_data(state+3);
    
    
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
  fclose(fp);
  return 0;
}



