#include <iostream>
#include <cmath>

#include "position.h"
#include "circle.h"
#include "comrate.h"

namespace ComLibSim
{

ComRate::ComRate ():
  m_circle (),
  m_rate (0)
{
}

ComRate::ComRate (const Position& center, double radius, double rate):
  m_circle (center, radius),
  m_rate (rate)
{
}

ComRate::ComRate (const Circle& circle, double rate):
  m_circle (circle),
  m_rate (rate)
{
}

ComRate::ComRate (const ComRate& comrate):
  m_circle (comrate.m_circle),
  m_rate (comrate.m_rate)
{
}

ComRate::~ComRate ()
{
}

Circle& ComRate::get_circle ()
{
  return m_circle;
}

double ComRate::get_rate () const
{
  return m_rate;
}

ComRate& ComRate::get ()
{
  return *this;
}

void ComRate::set_circle (const Circle& circle)
{
  m_circle = circle;
}

void ComRate::set_rate (double rate)
{
  m_rate = rate;
}

void ComRate::set (const Position& center, double radius, double rate)
{
  m_circle.set (center, radius);
  m_rate = rate;
}

void ComRate::set (const Circle& circle, double rate)
{
  m_circle.set (circle);
  m_rate = rate;
}

void ComRate::set (const ComRate& comrate)
{
  m_circle = comrate.m_circle;
  m_rate = comrate.m_rate;
}

double ComRate::get_rate_at (const Position& position) const
{
  if (m_circle.contains (position))
    return m_rate;

  return 0.0;
}

void ComRate::write (std::ostream& output) const
{
  m_circle.write ();
  output << " rate=" << m_rate;
}

void ComRate::write_ln (std::ostream& output) const
{
  m_circle.write ();
  output << " rate=" << m_rate << std::endl;
}

}
