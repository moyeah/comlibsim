#include <iostream>

#include "position.h"
#include "point.h"
#include "circle.h"
#include "comrate.h"
#include "sensor.h"

namespace ComLibSim
{

Sensor::Sensor ():
  m_position (),
  m_accumulator (),
  m_rate_map ()
{
}

Sensor::Sensor (const Position& position,
                const Accumulator& accumulator,
                const RateMap& rate_map):
  m_position (position),
  m_accumulator (accumulator),
  m_rate_map (rate_map)
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

RateMap& Sensor::get_rate_map ()
{
  return m_rate_map;
}

void Sensor::set_position (const Position& position)
{
  m_position.set (position);
}

void Sensor::set_accumulator (const Accumulator& accumulator)
{
  m_accumulator.set (accumulator);
}

void Sensor::set_rate_map (const RateMap& rate_map)
{
  m_rate_map.set (rate_map);
}

}
