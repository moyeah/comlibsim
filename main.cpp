#include <iostream>
#include <string>
#include <vector>

#include "point.h"
#include "circle.h"
#include "position.h"
#include "accumulator.h"
#include "comrate.h"
#include "sensor.h"

void write (std::string message);
void write_ln (std::string message);

void test_point ();
void test_circle ();
void test_position ();
void test_accumulator ();
void test_comrate ();
void test_sensor ();

int main ()
{
  test_point ();
  test_circle ();
  test_position ();
  test_accumulator ();
  test_comrate ();
  test_sensor ();

  return 0;
}

void write (std::string message)
{
  std::cout << message;
}

void write_ln (std::string message)
{
  std::cout << message << std::endl;
}

void test_point ()
{
  using namespace ComLibSim;

  write_ln ("Testing Point class");

  Point p_0;
  Point p_1 (1.0, 2.0);
  Point p_2 (p_0);

  write_ln ("Init Point");
  write ("1st point -> ");
  p_0.write_ln ();
  write ("2nd point -> ");
  p_1.write_ln ();
  write ("3rd point -> ");
  p_2.write_ln ();

  write_ln ("Operator =");
  p_0 = p_1;
  std::cout << p_0 << " = " << p_1 << std::endl;

  write_ln ("New");
  p_0 = Point ();
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

  write_ln ("Set x/y  Point");
  write ("1st point -> ");
  p_0.write_ln ();
  write ("2nd point -> ");
  p_1.write_ln ();
  write ("3rd point -> ");
  p_2.write_ln ();

  p_0.set (100.0, 200.0);
  p_1.set (300.0, 400.0);
  p_2.set (500.0, 600.0);

  write_ln ("Set Point");
  write ("1st point -> ");
  p_0.write_ln ();
  write ("2nd point -> ");
  p_1.write_ln ();
  write ("3rd point -> ");
  p_2.write_ln ();

  p_0.set (p_1);
  p_1.set (p_2);
  p_2.set (Point (100.0, 200.0));

  write_ln ("Set from Point");
  write ("1st point -> ");
  p_0.write_ln ();
  write ("2nd point -> ");
  p_1.write_ln ();
  write ("3rd point -> ");
  p_2.write_ln ();

  write_ln ("Distance");
  std::cout << "From (0, 0) to " << p_0 << " -> " <<
            p_0.distance_to (0.0, 0.0) << std::endl;
  std::cout << "From " << p_1 << " to " << p_2 << " -> " <<
            p_1.distance_to (p_2) << std::endl;

  write_ln ("GET:");
  p_0.set (p_1.get ());
  p_0.write_ln ();
}

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
  std::cout << c_0 << " -> " << c_0.get_area () << std::endl;
  c_1.set_radius (2.0);
  write ("2nd circle -> ");
  std::cout << c_1 << " -> " << c_1.get_area () << std::endl;
  c_2.set_radius (3.0);
  write ("3rd circle -> ");
  std::cout << c_2 << " -> " << c_2.get_area () << std::endl;

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

void test_accumulator ()
{
  using namespace ComLibSim;

  write_ln ("Testing Accumulator class");

  Accumulator acc_0;
  Accumulator acc_1 (100);
  Accumulator acc_2 (acc_1);

  write ("Accumulator 1: ");
  if (!acc_0.is_empty ())
  {
    write_ln ("");
    acc_0.print ();
  }
  else
    write_ln ("IS EMPTY");

  write ("Accumulator 2: ");
  if (!acc_1.is_empty ())
  {
    write_ln ("");
    acc_1.print ();
  }
  else
    write_ln ("IS EMPTY");

  write ("Accumulator 3: ");
  if (!acc_2.is_empty ())
  {
    write_ln ("");
    acc_2.print ();
  }
  else
    write_ln ("IS EMPTY");

  std::cout << "Acc. 1 capacity = " << acc_0.get_capacity () << std::endl;
  std::cout << "Acc. 2 capacity = " << acc_1.get_capacity () << std::endl;
  std::cout << "Acc. 3 capacity = " << acc_2.get_capacity () << std::endl;

  acc_0.set_capacity (10);
  std::cout << "Acc. 1 capacity = " << acc_0.get_capacity () << std::endl;
  acc_0.fill_seq (20);
  std::cout << "Acc. 1 adata = " << acc_0.get_amount_data () << std::endl;
  std::cout << "Acc. 1 contents:" << std::endl;
  acc_0.print ();

  acc_1.set_capacity (5);
  std::cout << "Acc. 2 capacity = " << acc_1.get_capacity () << std::endl;
  acc_1.fill_seq (2);
  std::cout << "Acc. 2 adata = " << acc_1.get_amount_data () << std::endl;
  std::cout << "Acc. 2 contents:" << std::endl;
  acc_1.print ();

  acc_2.set_capacity (15);
  std::cout << "Acc. 3 capacity = " << acc_2.get_capacity () << std::endl;
  acc_2.fill_seq ();
  std::cout << "Acc. 3 adata = " << acc_2.get_amount_data () << std::endl;
  std::cout << "Acc. 3 contents:" << std::endl;
  acc_2.print ();

  acc_0.set_capacity (512);
  acc_0.fill_seq ();
//  acc_0.print ();
  std::cout << "Acc. 1 capacity = " << acc_0.get_capacity () << std::endl;
  std::cout << "Acc. 1 adata = " << acc_0.get_amount_data () << std::endl;

  acc_1.set_capacity (512);
  acc_1.fill_seq ();
//  acc_1.print ();
  std::cout << "Acc. 2 capacity = " << acc_1.get_capacity () << std::endl;
  std::cout << "Acc. 2 adata = " << acc_1.get_amount_data () << std::endl;

  acc_2.set_capacity (512);
  acc_2.fill_seq ();
//  acc_2.print ();
  std::cout << "Acc. 3 capacity = " << acc_2.get_capacity () << std::endl;
  std::cout << "Acc. 3 adata = " << acc_2.get_amount_data () << std::endl;

  std::cout << "Acc. 1 is full = " << acc_0.is_full () << std::endl;
  std::cout << "Acc. 2 is full = " << acc_1.is_full () << std::endl;
  std::cout << "Acc. 3 is full = " << acc_2.is_full () << std::endl;

  acc_2.set_capacity (12);
  acc_2.print ();
  std::cout << "Acc. 3 capacity = " << acc_2.get_capacity () << std::endl;
  std::cout << "Acc. 3 adata = " << acc_2.get_amount_data () << std::endl;
  std::cout << "Acc. 3 is full = " << acc_2.is_full () << std::endl;
}

void test_comrate ()
{
  using namespace ComLibSim;

  write_ln ("Testing Accumulator class");

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
  std::cout << "Rate at: " << cr0.get_rate_at (p0) << std::endl;
  std::cout << "Rate at: " << cr0.get_rate_at (p1) << std::endl;
  p0.set_x (9);
  std::cout << "Rate at: " << cr0.get_rate_at (p0) << std::endl;
  p0.set_x (10);
  std::cout << "Rate at: " << cr0.get_rate_at (p0) << std::endl;
  p0.set_x (11);
  std::cout << "Rate at: " << cr0.get_rate_at (p0) << std::endl;

  cr0.set (p0, 123, 321);
  cr0.write_ln ();
}

void test_sensor ()
{
  using namespace ComLibSim;

  write_ln ("Testing SENSOR class");

  Sensor s0;
  Sensor s1 (10.0, 20.0, 100.0);
  Sensor s2 (Position (), 200.0);

  std::cout << "s0 position: " << s0.get_position () << std::endl;
  std::cout << "s1 position: " << s1.get_position () << std::endl;
  std::cout << "s2 position: " << s2.get_position () << std::endl;

  s0.get_position ().write_ln ();
  s2.set_position (30.0, 40.0);
  s2.get_position ().write_ln ();
  s1.set_position (s0.get_position ());
  s1.get_position ().write_ln ();
}
