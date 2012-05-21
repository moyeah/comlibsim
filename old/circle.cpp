#include <iostream>

#include "point.h"
#include "circle.h"

namespace ComLibSim
{

Circle::Circle ():
  m_center (),
  m_radius (0)
{
}

Circle::Circle (const Point& center, double radius):
  m_center (center),
  m_radius (radius)
{
}

Circle::Circle (const Circle& circle):
  m_center (circle.m_center),
  m_radius (circle.m_radius)
{
}

Circle::~Circle ()
{
}

Circle& Circle::operator = (const Circle& circle)
{
  this->copy (circle);
  
  return *this;
}

bool Circle::operator == (const Circle& circle) const
{
  return m_center == circle.m_center && m_radius == circle.m_radius;
}

bool Circle::operator != (const Circle& circle) const
{
  return ! operator == (circle);
}

std::ostream& operator << (std::ostream& output, const Circle& circle)
{
  circle.write (output);
  return output;
}

Point& Circle::get_center () 
{
  return m_center;
}

double Circle::get_radius () const
{
  return m_radius;
}

Circle& Circle::get ()
{
  return *this;
}

void Circle::set_center (const Point& center)
{
  m_center = center;
}

void Circle::set_radius (double radius)
{
  m_radius = radius;
}

void Circle::set (const Point& center, double radius)
{
  m_center = center;
  m_radius = radius;
}

void Circle::set (const Circle& circle)
{
  m_center = circle.m_center;
  m_radius = circle.m_radius;
}

void Circle::copy (const Circle& circle)
{
  if (this != &circle)
  {
    m_center = circle.m_center;
    m_radius = circle.m_radius;
  }
}

double Circle::area () const
{
  return PI * m_radius * m_radius;
}

bool Circle::contains (const Point& point) const
{
  Circle circle (*this);

  circle.set_radius (m_center.distance_to (point));

  return circle.area () <= this->area ();
}

bool Circle::contains (const Circle& circle) const
{
  return circle.area () <= this->area ();
}

void Circle::write (std::ostream& output) const
{
  output << m_center << " r=" << m_radius;
}

void Circle::write_ln (std::ostream& output) const
{
  output << m_center << " r=" << m_radius << std::endl;
}

}
