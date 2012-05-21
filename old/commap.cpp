#include <iostream>
#include <vector>
#include <algorithm>

#include "position.h"
#include "circle.h"
#include "comrate.h"
#include "commap.h"

namespace ComLibSim
{

ComMap::ComMap ():
  m_com_map ()
{
}

ComMap::ComMap (int nb_rates):
  m_com_map ()
{
  m_com_map.reserve (nb_rates);
}

ComMap::ComMap (const ComMap& com_map):
  m_com_map (com_map.m_com_map)
{
}

ComMap::~ComMap ()
{
}

ComMap& ComMap::operator = (const ComMap& com_map)
{
  this->copy (com_map);

  return *this;
}

ComMap& ComMap::get (const ComMap& com_map)
{
  return *this;
}

void ComMap::set (const ComMap& com_map)
{
//  m_com_map = com_map;
}

void ComMap::copy (const ComMap& com_map)
{
  if (this != &com_map)
  {
    m_com_map.clear ();
    m_com_map.reserve ((size_t) com_map.nb_rates ());

    for_each (com_map.begin (), com_map.end (), this->push ());
  }
}

void ComMap::push (const ComRate& com_rate)
{
  m_com_map.push_back (com_rate);

  this->sort ();
}

void ComMap::sort ()
{
  std::sort (m_com_map.begin (), m_com_map.end ());
}

const_iterator ComMap::begin () const
{
  return m_com_map.begin ();
}

const_iterator ComMap::end () const
{
  return m_com_map.end ();
}

int ComMap::nb_rates () const
{
  return static_cast<int>(m_com_map.size ());
}

double ComMap::min () const
{
  std::vector<ComRate>::const_iterator begin = m_com_map.begin ();
  std::vector<ComRate>::const_iterator end = m_com_map.end ();

  std::vector<ComRate>::const_iterator iter = min_element (begin, end);

  return iter->get_rate ();
}

double ComMap::max () const
{
  std::vector<ComRate>::const_iterator begin = m_com_map.begin ();
  std::vector<ComRate>::const_iterator end = m_com_map.end ();

  std::vector<ComRate>::const_iterator iter = max_element (begin, end);

  return iter->get_rate ();
}
  
double ComMap::avg () const
{
  double sum = 0.0;

  std::vector<ComRate>::const_iterator end = m_com_map.end ();

  for (std::vector<ComRate>::const_iterator iter = m_com_map.begin ();
       iter != end;
       ++iter)
  {
    sum += iter->get_rate ();
  }

  return sum / static_cast<double>(m_com_map.size ());
}

void ComMap::print (std::ostream& output) const
{
  std::vector<ComRate>::const_iterator end = m_com_map.end ();

  for (std::vector<ComRate>::const_iterator iter = m_com_map.begin ();
       iter != m_com_map.end ();
       ++iter)
  {
    iter->write_ln (output);
  }
}

}
