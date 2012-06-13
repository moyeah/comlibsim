#include <iostream>
#include <string>

#include "utils.hpp"
#include "../object.hpp"
#include "../accumulator.hpp"
#include "../comrate.hpp"
#include "../position.hpp"
#include "../sensor.hpp"

void test_sensor ()
{
  using namespace ComLibSim;

  write_ln ("Testing SENSOR class");

  Sensor s0 (Position (1.0, 10.0), 20.0, 100.0);
  Sensor s1 (Position (2.0, 30.0), 40.0, 200.0);

  s0.write_ln ();
  s1.write_ln ();

  s1.data (0.0);

  if (s1.is_empty ())
    write_ln ("s1 is empty");

  if (!s0.is_empty ())
    write_ln ("s0 is NOT empty");

  std::cout << "Testing hardcoded: " << s0 << std::endl;

  double data = s0.data ();
  double max_rate = s0.max_rate ();

  std::cout << "s0 data: " << data << " and max rate: " <<
               max_rate << std::endl;

  Position p0 (3.0, 40.0);

  double rate = s1.rate_at (p0);
  double distance = s1.distance_to (p0);

  std::cout << "s1 rate at " << p0 << " " << rate << std::endl;
  std::cout << "s1 distance to " << p0 << " " << distance << std::endl;
}
