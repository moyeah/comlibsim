#include "accumulator.hpp"

namespace ComLibSim
{

Accumulator::Accumulator ():
  m_amount_data (0.0)
{
}

Accumulator::Accumulator (double amount_data):
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

Object* Accumulator::object () const
{
  return new Accumulator (*this);
}

void Accumulator::copy (const Accumulator& accumulator)
{
  if (this != &accumulator)
    m_amount_data = accumulator.m_amount_data;
}

Accumulator& Accumulator::operator = (const Accumulator& accumulator)
{
  this->copy (accumulator);

  return *this;
}

bool Accumulator::operator == (const Accumulator& accumulator) const
{
  return m_amount_data == accumulator.m_amount_data;
}

bool Accumulator::operator != (const Accumulator& accumulator) const
{
  return ! operator == (accumulator);
}

bool Accumulator::operator > (const Accumulator& accumulator) const
{
  return m_amount_data > accumulator.m_amount_data;
}

bool Accumulator::operator < (const Accumulator& accumulator) const
{
  return m_amount_data < accumulator.m_amount_data;
}

bool Accumulator::operator >= (const Accumulator& accumulator) const
{
  return m_amount_data >= accumulator.m_amount_data;
}

bool Accumulator::operator <= (const Accumulator& accumulator) const
{
  return m_amount_data <= accumulator.m_amount_data;
}

double Accumulator::get_amount_data () const
{
  return m_amount_data;
}

void Accumulator::set_amount_data (double amount_data)
{
  m_amount_data = amount_data;
}

bool Accumulator::is_empty () const
{
  return m_amount_data <= 0.0;
}

void Accumulator::write (std::ostream& output) const
{
  output << "Amount data = " << m_amount_data;
}

void Accumulator::write_ln (std::ostream& output) const
{
  this->write (output);

  output << std::endl;
}

std::ostream& operator << (std::ostream& output,
                           const Accumulator& accumulator)
{
  accumulator.write (output);

  return output;
}

}
