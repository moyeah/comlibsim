/*
 *  sensor.cpp
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

#include "sensor.hpp"

namespace ComLibSim
{

Sensor::Sensor (const Position& position,
                double max_rate,
                double data,
                const std::string& tag):
  m_accumulator(Accumulator (data)),
  m_position(position),
  m_com_rate(ComRate (position, max_rate)),
  m_tag(tag),
  m_rate(0.0)
{
}

Sensor::Sensor (const Sensor& sensor):
  m_accumulator(sensor.m_accumulator),
  m_position(sensor.m_position),
  m_com_rate(sensor.m_com_rate),
  m_tag(sensor.m_tag),
  m_rate(sensor.m_rate)
{
}

Sensor::~Sensor ()
{
}

Object* Sensor::object () const
{
  return new Sensor (*this);
}

bool Sensor::operator == (const Sensor& sensor) const
{
  return m_accumulator == sensor.m_accumulator &&
         m_position == sensor.m_position &&
         m_com_rate == sensor.m_com_rate &&
         m_tag == sensor.m_tag &&
         m_rate == sensor.m_rate;
}

bool Sensor::operator != (const Sensor& sensor) const
{
  return ! operator == (sensor);
}

void Sensor::data (double data, double delta_time)
{
  double delta_data;

  if (data < 0.0)
  {
    delta_data = m_accumulator.get_amount_data ();
    m_accumulator.set_amount_data (0.0);
  }
  else
  {
    delta_data = m_accumulator.get_amount_data () - data;
    m_accumulator.set_amount_data (data);
  }

  m_rate = delta_data / delta_time;
}

void Sensor::rate (double rate)
{
  m_com_rate.set_act_rate (rate);
}

void Sensor::get_xy (double *xy) const
{
  xy[0] = m_position.get_x ();
  xy[1] = m_position.get_y ();
}

bool Sensor::is_empty () const
{
  return m_accumulator.is_empty ();
}

double Sensor::data () const
{
  return m_accumulator.get_amount_data ();
}

double Sensor::max_rate () const
{
  return m_com_rate.get_max_rate ();
}

double Sensor::rate () const
{
  return m_com_rate.get_act_rate ();
}

double Sensor::bandwidth () const
{
  return m_rate;
}

double Sensor::rate_at (const Position& position) const
{
  return m_com_rate.rate_at (position);
}

double Sensor::distance_to (const Position& position) const
{
  return m_position.distance_to (position);
}

void Sensor::write (std::ostream& output) const
{
  output << "Sensor at " << m_position << " " <<
            m_accumulator << " " << m_com_rate;
}

void Sensor::write_ln (std::ostream& output) const
{
  this->write (output);

  output << std::endl;
}

void Sensor::write_accumulator_log (std::ostream& output) const
{
  m_accumulator.write_log (output);
}

void Sensor::write_rate_log (std::ostream& output) const
{
  output << m_rate;
}

void Sensor::write_map (std::ostream& output) const
{
  m_position.write_map (output);
  output << " " << m_tag; 
}

void Sensor::write_tag (std::ostream& output) const
{
  output << m_tag; 
}

std::ostream& operator << (std::ostream& output,
                           const Sensor& sensor)
{
  sensor.write (output);

  return output;
}

}
