/*
 *  cluster.cpp
 *
 *  Copyright (C) 2011-2012  Daniel Sousa   <da.arada@gmail.com>
 *  Copyright (C) 2011-2012  Jorge Estrela  <jes@isep.ipp.pt>
 *
 *  Created by:
 *    Daniel Sousa  <da.arada@gmail.com>
 *
 *  Sponsor:
 *    Jorge Estrela  <jes@isep.ipp.pt>
 */

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

int Cluster::nb_sensors () const
{
  return static_cast<int>(m_sensors.size ());
}

void Cluster::add (const Sensor& sensor)
{
  m_sensors.push_back (sensor);
}

void Cluster::init_int ()
{
  m_sensors_int = m_sensors;
}

void Cluster::get_data (double *data)
{
  int j = 0;

  for (std::vector<Sensor>::const_iterator i = m_sensors.begin ();
       i != m_sensors.end ();
       i++)
  {
    data[j] = i->data ();
    j++;
  }
}

void Cluster::get_data_int (double *data)
{
  int j = 0;

  for (std::vector<Sensor>::const_iterator i = m_sensors_int.begin ();
       i != m_sensors_int.end ();
       i++)
  {
    data[j] = i->data ();
    j++;
  }
}

void Cluster::get_rate (double *rate)
{
  int j = 0;

  for (std::vector<Sensor>::const_iterator i = m_sensors.begin ();
       i != m_sensors.end ();
       i++)
  {
    rate[j] = i->rate ();
    j++;
  }
}

void Cluster::get_rate_int (double *rate,
                            const double *position,
                            double agv_bandwidth)
{
  int j = 0;
  Position position_int (position[0], position[1]);

  this->map_int (position_int, agv_bandwidth);
  
  for (std::vector<Sensor>::const_iterator i = m_sensors_int.begin ();
       i != m_sensors_int.end ();
       i++)
  {
    rate[j] = i->rate ();
    j++;
  }
}
  
void Cluster::set_data (double *data)
{
  int j = 0;

  for (std::vector<Sensor>::iterator i = m_sensors.begin ();
       i != m_sensors.end ();
       i++)
  {
    if (data[j] < 0)
      i->data (0.0);
    else
      i->data (data[j]);

    j++;
  }
}

void Cluster::set_data_int (const double *data)
{
  int j = 0;

  for (std::vector<Sensor>::iterator i = m_sensors_int.begin ();
       i != m_sensors_int.end ();
       i++)
  {
    i->data (data[j]);
    j++;
  }
}

void Cluster::set_rate (double *rate)
{
  int j = 0;

  for (std::vector<Sensor>::iterator i = m_sensors.begin ();
       i != m_sensors.end ();
       i++)
  {
    i->rate (rate[j]);
    j++;
  }
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

Cluster::ComMap Cluster::map_int (const Position& position,
                                  double agv_bandwidth)
{
  Cluster::ComMap selected_int; // Vector of sensors to connect

  m_act_bandwidth_int = selected_int.select (m_sensors_int, position);
  m_nb_act_sensors_int = static_cast<int> (selected_int.size ());
  m_scheduling_int = ((agv_bandwidth < m_act_bandwidth_int) &&
                  (m_nb_act_sensors_int > 0));

  if (m_scheduling_int)
  {
    for (ComMap::iterator i = selected_int.begin ();
         i != selected_int.end ();
         i++)
    {
      (*i)->rate (((*i)->rate () * agv_bandwidth) / m_act_bandwidth_int);
    }
  }

  return selected_int;
}

void Cluster::write (std::ostream& output) const
{
  output << "Cluster size: " << this->nb_sensors () <<
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

void Cluster::write_log (std::ostream& output) const
{
  for (std::vector<Sensor>::const_iterator i = m_sensors.begin ();
       i != m_sensors.end ();
       i++)
  {
    i->write_log (output);

    if (i != m_sensors.end ())
      output << " ";
  }
}

void Cluster::write_map (std::ostream& output) const
{
  for (std::vector<Sensor>::const_iterator i = m_sensors.begin ();
       i != m_sensors.end ();
       i++)
  {
    i->write_map (output);

    if (i != m_sensors.end ())
      output << std::endl;
  }
}

void Cluster::write_log_ln (double t, std::ostream& output) const
{
  output << t << " ";

  this->write_log (output);

  output << std::endl;
}

}
