#include <iostream>

#include "object.h"
#include "accumulator.h"
#include "comrate.h"
#include "position.h"
#include "sensor.h"

namespace ComLibSim
{

Sensor::Sensor (const Position& position,
                double max_rate,
                double data):
  m_accumulator(Accumulator (data)),
  m_position(position),
  m_com_rate(ComRate (m_position, max_rate))
{
}

Sensor::~Sensor ()
{
}

Object* Sensor::object () const
{
  return new Sensor (*this);
}

void Sensor::data (double data)
{
  m_accumulator.set_amount_data (data);
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

std::ostream& operator << (std::ostream& output,
                           const Sensor& sensor)
{
  sensor.write (output);

  return output;
}

}
