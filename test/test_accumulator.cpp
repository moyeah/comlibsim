#include <iostream>
#include <string>

#include "utils.h"
#include "../object.h"
#include "../accumulator.h"

void test_accumulator ()
{
  using namespace ComLibSim;

  write_ln ("Testing ACCUMULATOR class");

  Accumulator acc0;
  Accumulator acc1 (100.0);
  Accumulator acc2 (acc1);

  if (acc1 == acc2)
    write_ln ("acc1 == acc2");

  if (acc1 != acc0)
    write_ln ("acc1 != acc0");

  acc0.set_amount_data (10.0);
  acc2.set_amount_data (1000.0);

  if (acc0 < acc1)
    write_ln ("acc0 < acc1");

  if (acc0 > acc1)
    write_ln ("acc0 > acc1");

  acc2.set_amount_data (-20.0);

  if (acc2.is_empty ())
    write_ln ("acc2 is empty");

  acc0.write_ln ();
  acc1.write_ln ();

  std::cout << "This is hardcoded: " << acc2 << std::endl;
}
