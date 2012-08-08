#include <iostream>
#include <string>
#include <vector>

#include "utils.hpp"
#include "../object.hpp"
#include "../accumulator.hpp"
#include "../comrate.hpp"
#include "../position.hpp"
#include "../sensor.hpp"
#include "../cluster.hpp"

void test_cluster ()
{
  using namespace ComLibSim;

  write_ln ("Testing CLUSTER class");

  Sensor s0 (Position (1.0, 10.0), 100.0, 1000.0);
  Sensor s1 (Position (2.0, 20.0), 200.0, 2000.0);
  Sensor s2 (Position (3.0, 30.0), 300.0, 3000.0);
  Sensor s3 (Position (4.0, 40.0), 400.0, 4000.0);
  Sensor s4 (Position (5.0, 50.0), 500.0, 5000.0);
  Sensor s5 (Position (6.0, 60.0), 600.0, 0.0);
  Sensor s6 (Position (60000.0, 60000.0), 700.0, 7000.0);

  s0.write_ln ();
  s1.write_ln ();
  s2.write_ln ();
  s3.write_ln ();
  s4.write_ln ();
  s5.write_ln ();
  s6.write_ln ();

  Cluster c0;

  c0.add (s0);
  c0.add (s1);
  c0.add (s2);
  c0.add (s3);
  c0.add (s4);
  c0.add (s5);
  c0.add (s6);

  c0.write ();

  write_ln ("Closest sensor:");

  c0.closest (Position (20.0, 30.0)).write_ln ();

  write_ln ("Create COMMAP:");

  write ("COMMAP at position ");
  Position p0 (20.0, 30.0);
  p0.write_ln ();
  c0.map (p0, 100.0);
  c0.write ();

  write ("COMMAP at position ");
  Position p1 (200.0, 300.0);
  p1.write_ln ();
  c0.map (p1, 100.0);
  c0.write ();

  write ("COMMAP at position ");
  Position p2 (25.0, 3.0);
  p2.write_ln ();
  c0.map (p2, 200.0);
  c0.write ();

  write_ln ("Copy cluster");
  c0.init_int ();
  Position p3 (0.0, 0.0);
  c0.map_int (p3, 200.0);
  c0.write ();
}
