/*
 *  comrate.cpp
 *
 *  Copyright (C) 2011-2012  Daniel Sousa   <da.arada@gmail.com>
 *  Copyright (C) 2011-2012  Jorge Estrela  <jes@isep.ipp.pt>
 *
 *  Created by:
 *    Daniel Sousa  <da.arada@gmail.com>
 *
 *  Sponsor:
 *    Jorge Estrela  <jes@isep.ipp.pt>
 */

#include "comrate.hpp"

namespace ComLibSim
{

ComRate::ComRate ():
  m_reference (new Position()),
  m_max_rate (0.0),
  m_act_rate (0.0)
{
}

ComRate::ComRate (const Position& reference,
                  double max_rate,
                  double act_rate):
  m_reference (new Position (reference)),
  m_max_rate (max_rate),
  m_act_rate (act_rate)
{
}

ComRate::ComRate (const ComRate& com_rate):
  m_reference (com_rate.m_reference),
  m_max_rate (com_rate.m_max_rate),
  m_act_rate (com_rate.m_act_rate)
{
}

ComRate::~ComRate ()
{
}

Object* ComRate::object () const
{
  return new ComRate (*this);
}

bool ComRate::operator == (const ComRate& com_rate) const
{
  return m_max_rate == com_rate.m_max_rate;
}

bool ComRate::operator != (const ComRate& com_rate) const
{
  return ! operator == (com_rate);
}

bool ComRate::operator > (const ComRate& com_rate) const
{
  return m_max_rate > com_rate.m_max_rate;
}

bool ComRate::operator < (const ComRate& com_rate) const
{
  return m_max_rate < com_rate.m_max_rate;
}

bool ComRate::operator >= (const ComRate& com_rate) const
{
  return m_max_rate >= com_rate.m_max_rate;
}

bool ComRate::operator <= (const ComRate& com_rate) const
{
  return m_max_rate <= com_rate.m_max_rate;
}

void ComRate::set_act_rate (double act_rate)
{
  m_act_rate = act_rate;
}

double ComRate::get_max_rate () const
{
  return m_max_rate;
}

double ComRate::get_act_rate () const
{
  return m_act_rate;
}

double ComRate::rate_at (double distance) const
{
  if (distance < m_radius_low)
    return (- m_max_rate);

  if (distance < m_radius_high)
    return (- (m_max_rate * ::exp (1 - (distance / m_radius_low))));
//    return - m_max_rate * ::pow (10.0, -0.024 * distance);

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

  output << " Actual rate=" << this->get_act_rate () <<
            std::endl << "Rates: ";

  for (int i = 0; i < 100; i=i+20)
  {
    output << this->rate_at ((double) i) << " ";
  }
}

void ComRate::write_ln (std::ostream& output) const
{
  this->write (output);
  
  output << "END" << std::endl;
}

void ComRate::write_log (std::ostream& output) const
{
  output << std::fixed << std::setprecision (10);
  if (m_act_rate >= 0.0)
    output << m_act_rate;
  else
    output << 0.0;
}

std::ostream& operator << (std::ostream& output,
                           const ComRate& com_rate)
{
  com_rate.write (output);

  return output;
}

}
