#include "ode_solvers.hpp"

#include <cstdlib>


#ifdef USE_GSL

void rkInit(void *rk_data1, int n, int m)
{
  rk_data_t *rk_data = (rk_data_t*) rk_data1;

	rk_data->n = n;
	rk_data->aux.input = (double *) malloc(sizeof(double)*m);
	rk_data->aux.new_state = (double *) malloc(sizeof(double)*n);

	const gsl_odeiv_step_type * T = gsl_odeiv_step_rkf45;	
  //const gsl_odeiv_step_type * T = gsl_odeiv_step_rk8pd;
  
  rk_data->s = gsl_odeiv_step_alloc (T, n);
  rk_data->c = gsl_odeiv_control_y_new (GSL_ABS_ERR, GSL_REL_ERR);
	rk_data->e = gsl_odeiv_evolve_alloc (n);
}

void rkFinish(void *rk_data1)
{
  rk_data_t *rk_data = (rk_data_t*) rk_data1;

	free(rk_data->aux.input);
	free(rk_data->aux.new_state);
	gsl_odeiv_evolve_free (rk_data->e);
	gsl_odeiv_control_free (rk_data->c);
	gsl_odeiv_step_free (rk_data->s);
}

void rkIntegrate(void *rk_data1, double dt, double *x0, double *input, int (*f)(double, const double *, double *,void*))
{
  rk_data_t *rk_data = (rk_data_t*) rk_data1;

	gsl_odeiv_step_reset(rk_data->s);
	gsl_odeiv_control_init(rk_data->c, GSL_ABS_ERR, GSL_REL_ERR, 1, 0);
	gsl_odeiv_evolve_reset(rk_data->e);
	
	gsl_odeiv_system sys = {f, NULL, rk_data->n, rk_data->aux.input};
	
	double t = 0.0, t1 = dt;

	while (t < t1) {
/*
		int status = gsl_odeiv_evolve_apply (rk_data->e, rk_data->c, rk_data->s,
				                                &sys, 
				                                &t, t1,
				                                &dt, x0);

  //heee, this never fails...
  
		if (status != GSL_SUCCESS) {
			 printf("GSL error\n");
			 exit(1);
		}  
*/

    gsl_odeiv_evolve_apply (rk_data->e, rk_data->c, rk_data->s,
				                                &sys, 
				                                &t, t1,
				                                &dt, x0);
  }

}

#else

void rkInit(void *rk_data1, int n, int m)
{
  rk_data_t *rk_data = (rk_data_t*) rk_data1;
	rk_data->n = n;
	rk_data->aux.input = (double *) malloc(sizeof(double)*m);
	rk_data->aux.new_state = (double *) malloc(sizeof(double)*n);
	rk_data->k1 = (double *) malloc(sizeof(double)*n);
	rk_data->k2 = (double *) malloc(sizeof(double)*n);
	rk_data->k3 = (double *) malloc(sizeof(double)*n);
	rk_data->k4 = (double *) malloc(sizeof(double)*n);		
	rk_data->tmp = (double *) malloc(sizeof(double)*n);
}

void rkFinish(void *rk_data1)
{
  rk_data_t *rk_data = (rk_data_t*) rk_data1;

	free(rk_data->aux.input);
	free(rk_data->aux.new_state);
	free(rk_data->k1);
	free(rk_data->k2);
	free(rk_data->k3); 
	free(rk_data->k4); 
	free(rk_data->tmp);
}

void rkIntegrate(void *rk_data, double dt, double *x0, double *input, int (*f)(double, const double *, double *,void*))
{
  int i;
  int n = ((rk_data_t*) rk_data)->n;
	double *k1 = ((rk_data_t*) rk_data)->k1;
	double *k2 = ((rk_data_t*) rk_data)->k2;
	double *k3 = ((rk_data_t*) rk_data)->k3;
	double *k4 = ((rk_data_t*) rk_data)->k4;		
	double *tmp = ((rk_data_t*) rk_data)->tmp;

	
	f(0,x0,k1,input);
	for(i=0;i<n;++i)
		tmp[i]=x0[i]+k1[i]*dt/2;
	f(0,tmp,k2,input);
	for(i=0;i<n;++i)
		tmp[i]=x0[i]+k2[i]*dt/2;	
	f(0,tmp,k3,input);
	for(i=0;i<n;++i)
		tmp[i]=x0[i]+k3[i]*dt;	
	f(0,tmp,k4,input);
	
	for(i=0;i<n;++i)
		x0[i]=x0[i]+dt/6*(k1[i]+2*k2[i]+2*k3[i]+k4[i]);
}	


void eulerIntegrate(void *rk_data, double dt, double *x0, double *input, int (*f)(double, const double *, double *,void*))
{
  int i;
  int n = ((rk_data_t*) rk_data)->n;
	double *k1 = ((rk_data_t*) rk_data)->k1;
	
	f(0,x0,k1,input);
	
	for(i=0;i<n;++i)
		x0[i]=x0[i]+dt*k1[i];
}	

#endif
