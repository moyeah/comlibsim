#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
#include "../object.h"
#include "../accumulator.h"
#include "../comrate.h"
#include "../position.h"
#include "../sensor.h"
#include "../cluster.h"

void test_cluster ()
{
  using namespace ComLibSim;

  write_ln ("Testing CLUSTER class");

  Sensor s0 (Position (1.0, 10.0), 100.0, 1000.0);
  Sensor s1 (Position (2.0, 20.0), 200.0, 2000.0);
  Sensor s2 (Position (3.0, 30.0), 300.0, 3000.0);
  Sensor s3 (Position (4.0, 40.0), 400.0, 4000.0);
  Sensor s4 (Position (5.0, 50.0), 500.0, 5000.0);

  s0.write_ln ();
  s1.write_ln ();
  s2.write_ln ();
  s3.write_ln ();
  s4.write_ln ();

  Cluster c0;

  c0.add (s0);
  c0.add (s1);
  c0.add (s2);
  c0.add (s3);
  c0.add (s4);

  c0.write ();

  write_ln ("Closest sensor:");

  c0.closest (Position (20.0, 30.0)).write_ln ();
}

