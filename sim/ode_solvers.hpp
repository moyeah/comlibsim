//************************************************************************
// This code is work in progress in the context of my Phd program.
// Please read the license.txt file for terms of usage.
//
// Copyright (C) 2012 Jorge Estrela da Silva
//************************************************************************

//Nothing to see here. Changing the #define below would require a recompilation. 
//This build uses the fixed step ode solvers.


#ifndef ODE_SOLVERS_HPP_INCLUDED
#define ODE_SOLVERS_HPP_INCLUDED



//uncomment this line to use adaptive step from GSL library
//#define USE_GSL 1
//tolerances for adaptive step:
#define GSL_ABS_ERR 1.0e-6
#define GSL_REL_ERR 1.0e-6


typedef void (*integrator_func_t)(void *, double, double *, double *, int (*)(double, const double *, double *,void*));

typedef struct 
{
  double *input;
  double *new_state;
}
integration_data_t;

#ifdef USE_GSL

#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv.h>

typedef struct 
{
  integration_data_t aux;
  int n;
  gsl_odeiv_step *s; 
  gsl_odeiv_control *c;
  gsl_odeiv_evolve *e;
}
rk_data_t;

#else

typedef struct 
{
  integration_data_t aux;
  int n;
	double *k1;
	double *k2;
	double *k3;
	double *k4;		
	double *tmp;
}
rk_data_t;

#endif

void rkInit(void *rk_data, int, int);
void rkIntegrate(void *, double, double *, double *, int (*)(double, const double *, double *,void*));
void eulerIntegrate(void *, double, double *, double *, int (*)(double, const double *, double *,void*));
void rkFinish(void *rk_data);


#endif
