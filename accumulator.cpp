#include <vector>
#include <iostream>

#include "accumulator.h"

namespace ComLibSim
{

Accumulator::Accumulator ():
  m_capacity (0),
  m_amount_data (0)
{
}

Accumulator::Accumulator (unsigned int capacity, unsigned int amount_data):
  m_capacity (capacity),
  m_amount_data (amount_data)
{
  if (m_amount_data > m_capacity)
    m_amount_data = m_capacity;
}

Accumulator::Accumulator (const Accumulator& accumulator):
  m_capacity (accumulator.m_capacity),
  m_amount_data (accumulator.m_amount_data)
{
}

Accumulator::~Accumulator ()
{
}

unsigned int Accumulator::get_capacity () const
{
  return m_capacity;
}

unsigned int Accumulator::get_amount_data () const
{
  return m_amount_data;
}

void Accumulator::set_capacity (unsigned int capacity)
{
  m_capacity = capacity;

  if (m_capacity < m_amount_data)
    m_amount_data = m_capacity;
}

bool Accumulator::is_empty () const
{
  if (m_amount_data != 0)
    return false;

  return true;
}

bool Accumulator::is_full () const
{
  if (m_amount_data < m_capacity)
    return false;

  return true;
}

void Accumulator::fill ()
{
  m_amount_data = m_capacity;
}

void Accumulator::write (std::ostream& output) const
{
  output << "Capacity = " << m_capacity << "Amount data = " << m_amount_data;
}

void Accumulator::write_ln (std::ostream& output) const
{
  output << "Capacity = " << m_capacity << "Amount data = " << m_amount_data << std::endl;
}

}
