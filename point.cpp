#include <cmath>
#include <iostream>

#include "point.h"

namespace ComLibSim
{

Point::Point ():
  m_x (0),
  m_y (0)
{
}

Point::Point (double x, double y):
  m_x (x),
  m_y (y)
{
}

Point::Point (const Point& point):
  m_x (point.m_x),
  m_y (point.m_y)
{
}

Point::~Point ()
{
}

Point& Point::operator = (const Point& point)
{
  this->copy (point);

  return *this;
}

bool Point::operator == (const Point& point) const
{
  return m_x == point.m_x && m_y == point.m_y;
}

bool Point::operator != (const Point& point) const
{
  return ! operator == (point);
}

std::ostream& operator << (std::ostream& output, const Point& point)
{
  point.write (output);
  return output;
}

double Point::get_x () const
{
  return m_x;
}

double Point::get_y () const
{
  return m_y;
}

Point& Point::get ()
{
  return *this;
}

void Point::set_x (double x)
{
  m_x = x;
}

void Point::set_y (double y)
{
  m_y = y;
}

void Point::set (double x, double y)
{
  m_x = x;
  m_y = y;
}

void Point::set (const Point& point)
{
  m_x = point.m_x;
  m_y = point.m_y;
}

void Point::copy (const Point& point)
{
  if (this != &point)
  {
    m_x = point.m_x;
    m_y = point.m_y;
  }
}

double Point::distance_to (double x, double y) const
{
  return ::sqrt (::pow (m_x - x, 2) + ::pow (m_y - y, 2));
}

double Point::distance_to (const Point& point) const
{
  return ::sqrt (::pow (m_x - point.m_x, 2) + ::pow (m_y - point.m_y, 2));
}

void Point::write (std::ostream& output) const
{
  output << "(" << m_x << ", " << m_y << ")";
}

void Point::write_ln (std::ostream& output) const
{
  output << "(" << m_x << ", " << m_y << ")" << std::endl;
}

}
