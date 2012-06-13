#include <iostream>
#include <vector>

#include "object.hpp"
#include "accumulator.hpp"
#include "comrate.hpp"
#include "position.hpp"
#include "sensor.hpp"
#include "cluster.hpp"

namespace ComLibSim
{

double Cluster::ComMap::select (std::vector<Sensor>& sensors,
                                const Position& position)
{
  double bandwidth = 0.0;
  
  for (std::vector<Sensor>::iterator i = sensors.begin ();
       i != sensors.end ();
       i++)
  {
	double rate = i->rate_at (position);
	
    if (!i->is_empty () && rate != 0.0)
    {
	    bandwidth += rate;
      i->rate (rate);
      push_back (i);
    }
  }

  return bandwidth;
}

void Cluster::ComMap::write (std::ostream& output) const
{
  for (ComMap::const_iterator i = begin ();
       i != end ();
       i++)
  {
    (*i)->write_ln (output);
  }
}

Cluster::Cluster (int nb):
  m_sensors (),
  m_nb_act_sensors (0),
  m_act_bandwidth (0.0),
  m_scheduling (false)
{
  m_sensors.reserve (nb);
}

Cluster::~Cluster ()
{
}

int Cluster::nb_act_sensors () const
{
  return m_nb_act_sensors;
}
double Cluster::act_bandwidth () const
{
  return m_act_bandwidth;
}

bool Cluster::scheduling () const
{
  return m_scheduling;
}

void Cluster::add (const Sensor& sensor)
{
  m_sensors.push_back (sensor);
}

Sensor& Cluster::closest (const Position& position)
{
  double ref_distance = 0.0;
  double distance = 0.0;

  std::vector<Sensor>::iterator selected = m_sensors.begin ();

  for (std::vector<Sensor>::iterator i = m_sensors.begin ();
       i != m_sensors.end ();
       i++)
  {
    distance = i->distance_to (position);

    if ((!i->is_empty ()) &&
        ((distance < ref_distance) || (ref_distance == 0.0)))
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

Cluster::ComMap Cluster::map (const Position& position,
                              double agv_bandwidth)
{
  Cluster::ComMap selected; // Vector of sensors to connect

  m_act_bandwidth = selected.select (m_sensors, position);
  m_nb_act_sensors = static_cast<int> (selected.size ());
  m_scheduling = ((agv_bandwidth < m_act_bandwidth) &&
                  (m_nb_act_sensors > 0));

  if (m_scheduling)
  {
    for (ComMap::iterator i = selected.begin ();
         i != selected.end ();
         i++)
    {
      (*i)->rate (((*i)->rate () * agv_bandwidth) / m_act_bandwidth);
    }
  }

  return selected;
}

void Cluster::write (std::ostream& output) const
{
  output << "Cluster size: " <<
            static_cast<unsigned>(m_sensors.size ()) <<
            std::endl <<
            "Nb of active sensors: " << m_nb_act_sensors <<
            std::endl <<
            "Cluster active bandwidth: " << m_act_bandwidth <<
            std::endl <<
            "Scheduling: " << (m_scheduling == 0 ? "false" : "true") <<
            std::endl;

  for (std::vector<Sensor>::const_iterator i = m_sensors.begin ();
       i != m_sensors.end ();
       i++)
  {
    i->write_ln (output);
  }
}

}
