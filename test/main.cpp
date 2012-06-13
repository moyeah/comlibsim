#include "test_accumulator.hpp"
#include "test_comrate.hpp"
#include "test_position.hpp"
#include "test_sensor.hpp"
#include "test_cluster.hpp"

int main ()
{
  test_accumulator ();
  test_comrate ();
  test_position ();
  test_sensor ();
  test_cluster ();

  return 0;
}
