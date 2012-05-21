#include <cmath>
#include <iostream>

#include "position.h"
#include "comrate.h"

namespace ComLibSim
{

ComRate::ComRate ()
{
}

ComRate::ComRate (const Position& reference):
  m_reference (&reference)
{
}

ComRate::~ComRate ()
{
}

std::ostream& operator << (std::ostream& output, const ComRate& comrate)
{
  comrate.write (output);
  return output;
}

const Position& ComRate::get_reference () const
{
  return *m_reference;
}

ComRate& ComRate::get ()
{
  return *this;
}

void ComRate::set_reference(const Position& reference)
{
  m_reference = &reference;
}

double ComRate::rate_at (double distance) const
{
  if (distance < m_radius_low)
    return 4.0;

  if (distance < m_radius_high)
    return 12 * ::pow (10.0, -0.024 * distance);

  return 0.0;
}

double ComRate::rate_at (const Position& position) const
{
  double distance = m_reference->distance_to (position);

  return this->rate_at (distance);
}

void ComRate::write (std::ostream& output) const
{
  m_reference->write ();

  for (int i = 0; i < 100; i=i+10)
    output << " rate=" << this->rate_at ((double) i);
}

void ComRate::write_ln (std::ostream& output) const
{
  m_reference->write ();

  for (int i = 0; i < 100; i=i+10)
    output << " rate=" << this->rate_at ((double) i) << std::endl;
}

}
