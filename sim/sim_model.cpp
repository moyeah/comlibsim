#include <cmath>
#include <cstdio>

#include "../cluster.hpp"


#define MAX_AUV_BANDWIDTH 1.0
#define MAX_NORM 1.0

using namespace ComLibSim;
static Cluster c0;


#define PI 3.14159265358979323846
inline double
normalizeRadian(double a)
{
  a = fmod(a, 2*PI);
  if (a <= -PI)
    a += 2*PI;
  if (a > PI)
    a -= 2*PI;

  return a;
}

  
Cluster* init_cluster()
{
  return &c0;
}

int dynamics(double t,  const double *x0, double *deriv, void *param)
{
  double *input = (double *) param;

  if(input[1]>0.26)
    input[1]=0.26;
  else
    if(input[1]<0.26)
      input[1]=-0.26;
  
  deriv[0] = input[0]*cos(x0[2]);
  deriv[1] = input[0]*sin(x0[2]);    
  deriv[2] = input[1];
  
  c0.set_data_int(x0+3);
  
#if 1
  c0.get_rate_int(deriv+3, x0, MAX_AUV_BANDWIDTH);
#else  
  for(int i=0; i< c0.nb_sensors(); ++i)
    if(x0[3+i]>0)
      deriv[3+i] = -1;
    else
      deriv[3+i] = 0;
#endif
      
  return 0;
}

void compute_control(const double *state, double * const input)
{
  
#if 1
  if (c0.is_empty ())
  {
    // STOP vehicle
    input[0] = 0;
    input[1] = 0;
  }
  else if (c0.bandwidth () >= MAX_AUV_BANDWIDTH)
	{
	  //input[0] = 1;
	  //input[1] = 0.5;

	  //input[0] = 10;
	  //input[1] = 0.25;

	  input[0] = 0;
	  input[1] = 0;
	}
  else
  {
    double xy[2];

    c0.closest (Position (state[0], state[1])).get_xy (xy);

    double x = xy[0] - state[0];
    double y = xy[1] - state[1];
    double norm = std::sqrt(x * x + y * y);
    double angle = std::atan2(y, x);

    //regular a orientação do veículo para essa direção
    double err=normalizeRadian(angle-state[2]);

		if(norm > MAX_NORM)
			norm = MAX_NORM;
		else if(norm < -MAX_NORM)
			norm = -MAX_NORM;
				
    input[0]=norm;
    input[1]=20*err;
  }

#else

  input[0]=10;
  input[1]=0.25;
  
#endif  
}
