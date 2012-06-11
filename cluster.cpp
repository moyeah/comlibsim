#include <iostream>
#include <vector>

#include "object.h"
#include "accumulator.h"
#include "comrate.h"
#include "position.h"
#include "sensor.h"
#include "cluster.h"

namespace ComLibSim
{

Cluster::Cluster (int nb):
  m_sensors ()
{
  m_sensors.reserve (nb);
}

Cluster::~Cluster ()
{
}

void Cluster::add (const Sensor& sensor)
{
  m_sensors.push_back (sensor);
}

Sensor& Cluster::closest (const Position& position)
{
  double ref_distance = 0.0;
  double distance = 0.0;

  std::vector<Sensor>::iterator selected;

  for (std::vector<Sensor>::iterator i = m_sensors.begin ();
       i != m_sensors.end ();
       i++)
  {
    distance = i->distance_to (position);

    if ((distance < ref_distance) || (ref_distance == 0.0))
    {
      ref_distance = distance;
      selected = i;
    }
  }
  
  return *selected;
}

const Sensor& Cluster::closest (const Position& position) const
{
  return const_cast<Cluster*>(this)->closest (position);
}

void Cluster::write (std::ostream& output) const
{
  output << "Cluster size: " <<
            static_cast<unsigned>(m_sensors.size ()) << std::endl;

  for (std::vector<Sensor>::const_iterator i = m_sensors.begin ();
       i != m_sensors.end ();
       i++)
  {
    i->write_ln (output);
  }
}

}
