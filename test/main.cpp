#include "test_accumulator.h"
#include "test_comrate.h"
#include "test_position.h"
#include "test_sensor.h"
#include "test_cluster.h"

int main ()
{
  test_accumulator ();
  test_comrate ();
  test_position ();
  test_sensor ();
  test_cluster ();

  return 0;
}
