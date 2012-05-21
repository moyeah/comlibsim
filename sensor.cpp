#include <iostream>
#include <vector>

#include "equipament.h"
#include "accumulator.h"
#include "position.h"
#include "point.h"
#include "comrate.h"
#include "sensor.h"

namespace ComLibSim
{

Sensor::Sensor ():
  m_position (),
  m_accumulator (),
  m_com_rate ()
{
}

Sensor::Sensor (const Position& position,
                const Accumulator& accumulator,
                const ComRate& com_rate):
  m_position (position),
  m_accumulator (accumulator),
  m_com_rate (com_rate)
{
}

Sensor::~Sensor ()
{
}

Position& Sensor::get_position ()
{
  return m_position;
}

Accumulator& Sensor::get_accumulator ()
{
  return m_accumulator;
}

ComRate& Sensor::get_com_rate ()
{
  return m_com_rate;
}

Sensor& Sensor::get ()
{
  return *this;
}

void Sensor::set_position (const Position& position)
{
  m_position.set (position);
}

void Sensor::set_accumulator (const Accumulator& accumulator)
{
  m_accumulator.set (accumulator);
}

void Sensor::set_com_rate (const ComRate& com_rate)
{
  m_com_rate.set (com_rate);
}

void Sensor::set (const Position& position,
                  const Accumulator& accumulator,
                  const ComRate& com_rate)
{
  m_position.set (position);
  m_accumulator.set (accumulator);
  m_com_rate.set (com_rate);
}

}
