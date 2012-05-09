#include <iostream>

#include "accumulator.h"

namespace ComLibSim
{

Accumulator::Accumulator ():
  m_amount_data (0)
{
}

Accumulator::Accumulator (unsigned int amount_data):
  m_amount_data (amount_data)
{
}

Accumulator::Accumulator (const Accumulator& accumulator):
  m_amount_data (accumulator.m_amount_data)
{
}

Accumulator::~Accumulator ()
{
}

unsigned int Accumulator::get_amount_data () const
{
  return m_amount_data;
}

Accumulator& Accumulator::get ()
{
  return *this;
}

void Accumulator::set_amount_data (unsigned int amount_data)
{
  m_amount_data = amount_data;
}

void Accumulator::set (const Accumulator& accumulator)
{
  m_amount_data = accumulator.m_amount_data;
}

bool Accumulator::is_empty () const
{
  if (m_amount_data != 0)
    return false;

  return true;
}

void Accumulator::write (std::ostream& output) const
{
  output << "Amount data = " << m_amount_data;
}

void Accumulator::write_ln (std::ostream& output) const
{
  output << "Amount data = " << m_amount_data << std::endl;
}

}
