#include <iostream>
#include <string>

#include "utils.h"

#include "../point.h"
#include "../circle.h"

void test_circle ()
{
  using namespace ComLibSim;

  write_ln ("Testing Circle class");

  Circle c_0;
  Circle c_1 (Point (1.0, 2.0), 3.0);
  Circle c_2 (c_0);

  write_ln ("Init Circle");
  write ("1st circle -> ");
  c_0.write_ln ();
  write ("2nd circle -> ");
  c_1.write_ln ();
  write ("3rd circle -> ");
  c_2.write_ln ();

  write_ln ("Compare");
  c_0.write ();
  if (c_0 == c_0)
    write (" == ");
  else
    write (" != ");
  c_0.write_ln ();
  c_0.write ();
  if (c_0 == c_1)
    write (" == ");
  else
    write (" != ");
  c_1.write_ln ();

  c_0.set_center (Point (10.0, 20.0));
  c_0.set_radius (30.0);
  c_1.set_center (Point (40.0, 50.0));
  c_1.set_radius (60.0);
  c_2.set_center (Point (70.0, 80.0));
  c_2.set_radius (90.0);

  write_ln ("Set center/radius Circle");
  write ("1st circle -> ");
  c_0.write_ln ();
  write ("2nd circle -> ");
  c_1.write_ln ();
  write ("3rd circle -> ");
  c_2.write_ln ();

  c_0.set (Point (100.0, 200.0), 300.0);
  c_1.set (Point (400.0, 500.0), 600.0);
  c_2.set (Point (700.0, 800.0), 900.0);

  write_ln ("Set Circle");
  write ("1st circle -> ");
  c_0.write_ln ();
  write ("2nd circle -> ");
  c_1.write_ln ();
  write ("3rd circle -> ");
  c_2.write_ln ();

  write_ln ("Area");
  c_0.set_radius (1.0);
  write ("1st circle -> ");
  std::cout << c_0 << " -> " << c_0.area () << std::endl;
  c_1.set_radius (2.0);
  write ("2nd circle -> ");
  std::cout << c_1 << " -> " << c_1.area () << std::endl;
  c_2.set_radius (3.0);
  write ("3rd circle -> ");
  std::cout << c_2 << " -> " << c_2.area () << std::endl;

  write_ln ("Contains");
  Point p_0 (5.0, 5.0);
  c_0.set (Point (), 10.0);
  c_0.write ();
  if (c_0.contains (p_0))
    write (" contains ");
  else
    write (" NOT contains ");
  p_0.write_ln ();
  p_0.set (15.0, 15.0);
  c_0.write ();
  if (c_0.contains (p_0))
    write (" contains ");
  else
    write (" NOT contains ");
  c_0.write_ln ();
  c_0.write ();
  c_1 = c_0;
  c_1.set_radius (15.0);
  if (c_0.contains (c_1))
    write (" contains ");
  else
    write (" NOT contains ");
  c_1.write_ln ();
  c_1.write ();
  if (c_1.contains (c_0))
    write (" contains ");
  else
    write (" NOT contains ");
  c_0.write_ln ();
}
