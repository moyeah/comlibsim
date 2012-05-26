#include <iostream>
#include <string>

#include "utils.h"
#include "../object.h"
#include "../comrate.h"
#include "../position.h"

void test_comrate ()
{
  using namespace ComLibSim;

  write_ln ("Testing COMRATE class");

  Position p0; 
  Position p1 (0.0, 0.0);

  ComRate cr0 (p0, 0.0);
  ComRate cr1 (p1, 10.0);
  ComRate cr2 (cr1);

  if (cr1 == cr2)
    write_ln ("cr1 == cr2");

  if (cr1 != cr0)
    write_ln ("cr1 != cr0");

  cr0.write_ln ();

  std::cout << "Test hardcoded: " << cr2 << std::endl;

  double rate = cr1.rate_at (Position (10.0, 20.0));
  std::cout << "Rate: " << rate << std::endl;
}
