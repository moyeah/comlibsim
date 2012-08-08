#include <cmath>
#include <cstdio>

//isto não deveria ser necessário
#include <iostream>
#include <vector>

//nota: adicionar regra .cpp.o à makefile (para ter o -Wall)

//não deveria ser necessário adicionar todos os header files
#include "../object.hpp"
#include "../accumulator.hpp"
#include "../comrate.hpp"
#include "../position.hpp"
#include "../sensor.hpp"
#include "../cluster.hpp"


#define MAX_AV_BANDWIDTH 50.0

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

  
  Sensor s0 (Position (0.0, 0.0), 50.0, 500.0);
  Sensor s1 (Position (100.0, 0.0), 50.0, 500.0);
  Sensor s2 (Position (0.0, 100.0), 50.0, 500.0);
  Sensor s3 (Position (100.0, 100.0), 50.0, 500.0);

  s0.write_ln ();
  s1.write_ln ();
  s2.write_ln ();
  s3.write_ln ();

  c0.add (s0);
  c0.add (s1);
  c0.add (s2);
  c0.add (s3);
  
  printf("%d sensors\n", c0.nb_sensors());

  c0.write ();

printf ("\n\nClosest sensor: ");
c0.closest (Position (0.0, 0.0)).write_ln ();
printf ("\n\n");
  
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
  
  //completar com derivadas da "informação por copiar" em cada sensor
  //NOTA: actualizar a variável n_dim em sim_main.cpp
  //deriv[3]=...
  //deriv[4]=

  c0.set_data_int(x0+3);
  
#if 1
c0.closest (Position (0.0, 0.0)).write_ln ();
//c0.write ();
//Sensor my_sensor = c0.closest (Position (0.0, 0.0));
//my_sensor.rate_at (Position (0.0, 0.0));

//  c0.get_rate_int(deriv+3, x0, MAX_AV_BANDWIDTH);
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
  //1 - identificar sensor mais proximo
  //2 - determinar se 
  //a) data rate do sensor mais próximo é máxima, ou
  //b) se já atingiu o máximo do canal com o veículo. 
  //Se alguma destas condições for verdadeira, o veículo de verá parar (v=0)
  //Caso contrário, continua a viajar na direção do sensor.
  //Exemplo: 
  
#if 0  
  double xy[2];
  sensor = sensors->getClosest();
  dr = sensor->GetDataRate(state);
  if(sensor->getMaxDataRate()==dr || dr==vehicle_max_data_rate)
  {
    input[0]=0;//velocidade do veic (m/s)
    input[1]=0;//direção veiculo (rad)
  }
  else
  {
    //tirar a direção para o sensor
    sensor->getLocation(xy);
    
    double x=xy[0]-state[0];
    double y=xy[1]-state[1];
    norm = std::sqrt(x * x + y * y);
    angle = std::atan2(y, x);
        
    //regular a orientação do veículo para essa direção
    double err=normalizeRadian(angle-state[1]);
    input[0]=1;
    input[1]=20*err;
  }  

#else

  input[0]=1;
  input[1]=0.25;
  
#endif  
}
