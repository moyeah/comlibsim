#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
#include "../position.h"
#include "../circle.h"
#include "../comrate.h"

void test_comrate ()
{
  using namespace ComLibSim;

  write_ln ("Testing ComRate class");

  Position position;

  ComRate comrate_0;
  ComRate comrate_1 (Circle (Point (), 10), 100);
  ComRate comrate_2 (comrate_1);
  ComRate comrate_3 (position, 100, 12);

  comrate_0.write_ln ();
  comrate_1.write_ln ();
  comrate_2.write_ln ();
  comrate_3.write_ln ();

  write_ln ("Changing settings:");

  comrate_3.set_rate (9);
  comrate_3.write_ln ();

  comrate_0.set (comrate_3);
  comrate_0.write_ln ();

  comrate_1.set (Circle (Point (1.0, 1.0), 25), 30);
  comrate_1.write_ln ();

  Position p0, p1 (30.0, 0.0);
  ComRate cr0 (p0, 10, 30);

  std::cout << "Rate: " << cr0.get_rate () << std::endl;
  std::cout << "Rate at: " << p0.get () << " " << cr0.rate_at (p0) << std::endl;
  std::cout << "Rate at: " << p1.get () << " " << cr0.rate_at (p1) << std::endl;
  p0.set_x (9);
  std::cout << "Rate at: " << p0.get () << " " << cr0.rate_at (p0) << std::endl;
  p0.set_x (10);
  std::cout << "Rate at: " << p0.get () << " " << cr0.rate_at (p0) << std::endl;
  p0.set_x (11);
  std::cout << "Rate at: " << p0.get () << " " << cr0.rate_at (p0) << std::endl;

  cr0.set (p0, 123, 321);
  cr0.write_ln ();
}
