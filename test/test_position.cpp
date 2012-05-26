#include <iostream>
#include <string>

#include "utils.h"

#include "../object.h"
#include "../position.h"

void test_position ()
{
  using namespace ComLibSim;

  write_ln ("Testing POSITION class");

  Position p0;
  Position p1 (1.0, 2.0);
  Position p2 (p0);

  if (p0 == p2)
    write_ln ("p0 == p2");

  if (p1 != p0)
    write_ln ("p1 != p0");

  p0.write_ln ();

  double x = p1.get_x ();
  double y = p1.get_y ();

  std::cout << "Test hardcoded: " << x << ", " << y << std::endl;
  std::cout << "Test hardcoded: " << p2 << std::endl;

  double distance = p0.distance_to (p1);

  std::cout << "Distance from " << p0 << " to " << p1 << 
               " " << distance << std::endl;
}
