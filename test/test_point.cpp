#include <iostream>

#include "utils.h"

#include "../point.h"

void test_point ()
{
  using namespace ComLibSim;

  write_ln ("Testing Point class");

  Point p0;
  Point p1 (1.0, 2.0);
  Point p2 (p0);

  write_ln ("Init Point");
  write ("1st point -> ");
  p0.write_ln ();
  write ("2nd point -> ");
  p1.write_ln ();
  write ("3rd point -> ");
  p2.write_ln ();

  write_ln ("Operator =");
  p0 = p1;
  std::cout << p0 << " = " << p1 << std::endl;

  write_ln ("New");
  p0 = Point ();
  p0.write_ln ();

  write_ln ("Compare");
  p0.write ();
  if (p0 == p0)
    write (" == ");
  else
    write (" != ");
  p0.write_ln ();
  p0.write ();
  if (p0 == p1)
    write (" == ");
  else
    write (" != ");
  p1.write_ln ();

  p0.set_x (10.0);
  p0.set_y (20.0);
  p1.set_x (30.0);
  p1.set_y (40.0);
  p2.set_x (50.0);
  p2.set_y (60.0);

  write_ln ("Set x/y  Point");
  write ("1st point -> ");
  p0.write_ln ();
  write ("2nd point -> ");
  p1.write_ln ();
  write ("3rd point -> ");
  p2.write_ln ();

  p0.set (100.0, 200.0);
  p1.set (300.0, 400.0);
  p2.set (500.0, 600.0);

  write_ln ("Set Point");
  write ("1st point -> ");
  p0.write_ln ();
  write ("2nd point -> ");
  p1.write_ln ();
  write ("3rd point -> ");
  p2.write_ln ();

  p0.set (p1);
  p1.set (p2);
  p2.set (Point (100.0, 200.0));

  write_ln ("Set from Point");
  write ("1st point -> ");
  p0.write_ln ();
  write ("2nd point -> ");
  p1.write_ln ();
  write ("3rd point -> ");
  p2.write_ln ();

  write_ln ("Distance");
  std::cout << "From (0, 0) to " << p0 << " -> " <<
            p0.distance_to (0.0, 0.0) << std::endl;
  std::cout << "From " << p1 << " to " << p2 << " -> " <<
            p1.distance_to (p2) << std::endl;

  write_ln ("GET:");
  p0.set (p1.get ());
  p0.write_ln ();
}
