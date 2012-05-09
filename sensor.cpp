#include <iostream>
#include <vector>

#include "equipament.h"
#include "accumulator.h"
#include "position.h"
#include "point.h"
#include "circle.h"
#include "comrate.h"
#include "commap.h"
#include "sensor.h"

namespace ComLibSim
{

Sensor::Sensor ():
  m_position (),
  m_accumulator (),
  m_com_map ()
{
}

Sensor::Sensor (const Position& position,
                const Accumulator& accumulator,
                const ComMap& com_map):
  m_position (position),
  m_accumulator (accumulator),
  m_com_map (com_map)
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

ComMap& Sensor::get_com_map ()
{
  return m_com_map;
}

void Sensor::set_position (const Position& position)
{
  m_position.set (position);
}

void Sensor::set_accumulator (const Accumulator& accumulator)
{
  m_accumulator.set (accumulator);
}

void Sensor::set_com_map (const ComMap& com_map)
{
  m_com_map.set (com_map);
}

}
