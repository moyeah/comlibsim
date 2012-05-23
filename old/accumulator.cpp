#include <vector>
#include <iostream>

#include "accumulator.h"

namespace ComLibSim
{

Accumulator::Accumulator ():
  m_capacity (0)
{
}

Accumulator::Accumulator (unsigned int capacity):
  m_capacity (capacity)
{
}

Accumulator::Accumulator (const Accumulator& accumulator):
  m_registers (accumulator.m_registers),
  m_capacity (accumulator.m_capacity)
{
}

Accumulator::~Accumulator ()
{
}

unsigned int Accumulator::get_capacity () const
{
  return m_capacity;
}

void Accumulator::set_capacity (unsigned int capacity)
{
  if (capacity < static_cast<unsigned int>(m_registers.size ()))
    m_registers.erase (m_registers.begin () + capacity, m_registers.end ());

  m_capacity = capacity;
}

bool Accumulator::is_empty () const
{
  if (static_cast<int>(m_registers.size ()) != 0)
    return false;

  return true;
}

bool Accumulator::is_full () const
{
  if (static_cast<unsigned int>(m_registers.size ()) != m_capacity)
    return false;

  return true;
}

void Accumulator::fill_seq ()
{
  for (unsigned int i = 0;
       static_cast<unsigned int>(m_registers.size ()) < m_capacity;
       i++)
    m_registers.push_back (i);
}

void Accumulator::fill_seq (unsigned int nb_registers)
{
  for (unsigned int i = 0;
       static_cast<unsigned int>(m_registers.size ()) < nb_registers &&
         static_cast<unsigned int>(m_registers.size ()) < m_capacity;
       i++)
    m_registers.push_back (i);
}

void Accumulator::fill_rand ()
{
}

void Accumulator::fill_rand (unsigned int nb_registers)
{
}

unsigned int Accumulator::get_amount_data () const
{
  return static_cast<unsigned int>(m_registers.size ());
}

void Accumulator::print (std::ostream& output) const
{
  for (unsigned int i = 0;
       i < static_cast<unsigned int>(m_registers.size ());
       i++)
    output << "registor [" << i << "] = " << m_registers[i] << std::endl;
}

}
