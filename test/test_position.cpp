#include <iostream>
#include <string>

#include "utils.h"

#include "../point.h"
#include "../position.h"

void test_position ()
{
  using namespace ComLibSim;

  write_ln ("Testing Position class");

  Position p_0;
  Position p_1 (1.0, 2.0);
  Position p_2 (p_0);
  Position p_3 (Point (3.0, 4.0));

  write_ln ("Init Position");
  write ("1st position -> ");
  p_0.write_ln ();
  write ("2nd position -> ");
  p_1.write_ln ();
  write ("3rd position -> ");
  p_2.write_ln ();
  write ("4th position -> ");
  p_3.write_ln ();

  write_ln ("Operator =");
  p_0 = p_1;
  std::cout << p_0 << " = " << p_1 << std::endl;

  write_ln ("New");
  p_0 = Position ();
  p_0.write_ln ();

  write_ln ("Compare");
  p_0.write ();
  if (p_0 == p_0)
    write (" == ");
  else
    write (" != ");
  p_0.write_ln ();
  p_0.write ();
  if (p_0 == p_1)
    write (" == ");
  else
    write (" != ");
  p_1.write_ln ();

  p_0.set_x (10.0);
  p_0.set_y (20.0);
  p_1.set_x (30.0);
  p_1.set_y (40.0);
  p_2.set_x (50.0);
  p_2.set_y (60.0);
  p_3.set_x (70.0);
  p_3.set_y (80.0);

  write_ln ("Set x/y  Position");
  write ("1st position -> ");
  p_0.write_ln ();
  write ("2nd position -> ");
  p_1.write_ln ();
  write ("3rd position -> ");
  p_2.write_ln ();
  write ("4th position -> ");
  p_3.write_ln ();

  p_0.set (100.0, 200.0);
  p_1.set (300.0, 400.0);
  p_2.set (500.0, 600.0);
  p_3.set (700.0, 800.0);

  write_ln ("Set Position");
  write ("1st position -> ");
  p_0.write_ln ();
  write ("2nd position -> ");
  p_1.write_ln ();
  write ("3rd position -> ");
  p_2.write_ln ();
  write ("4th position -> ");
  p_3.write_ln ();

  p_0.set (p_1);
  p_1.set (p_2);
  p_2.set (Point (100.0, 200.0));
  p_3.set (Position (900.0, 1000.0));

  write_ln ("Set from Point");
  write ("1st point -> ");
  p_0.write_ln ();
  write ("2nd point -> ");
  p_1.write_ln ();
  write ("3rd point -> ");
  p_2.write_ln ();
  write ("4th position -> ");
  p_3.write_ln ();

  write_ln ("Distance");
  std::cout << "From (0, 0) to " << p_0 << " -> " <<
            p_0.distance_to (0.0, 0.0) << std::endl;
  std::cout << "From " << p_1 << " to " << p_2 << " -> " <<
            p_1.distance_to (p_2) << std::endl;
}
