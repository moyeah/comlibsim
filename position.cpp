#include <cmath>
#include <iostream>

#include "object.hpp"
#include "position.hpp"

namespace ComLibSim
{

Position::Position ():
  m_x(0.0),
  m_y(0.0)
{
}

Position::Position (double x, double y):
  m_x(x),
  m_y(y)
{
}

Position::Position (const Position& position):
  m_x(position.m_x),
  m_y(position.m_y)
{
}

Position::~Position ()
{
}

Object* Position::object () const
{
  return new Position (*this);
}

void Position::copy (const Position& position)
{
  if (this != &position)
  {
    m_x = position.m_x;
    m_y = position.m_y;
  }
}

Position& Position::operator = (const Position& position)
{
  this->copy (position);

  return *this;
}

bool Position::operator == (const Position& position) const
{
  return m_x == position.m_x && m_y == position.m_y;
}

bool Position::operator != (const Position& position) const
{
  return ! operator == (position);
}

double Position::get_x () const
{
  return m_x;
}

double Position::get_y () const
{
  return m_y;
}

double Position::distance_to (const Position& position) const
{
  return ::sqrt (::pow (m_x - position.m_x, 2) +
                 ::pow (m_y - position.m_y, 2));
}

void Position::write (std::ostream& output) const
{
  output << "(" << m_x << ", " << m_y << ")";
}

void Position::write_ln (std::ostream& output) const
{
  this->write (output);
  output << std::endl;
}

std::ostream& operator << (std::ostream& output,
                           const Position& position)
{
  position.write (output);

  return output;
}

}
