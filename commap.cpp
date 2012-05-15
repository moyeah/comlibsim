#include <iostream>
#include <vector>

#include "position.h"
#include "circle.h"
#include "comrate.h"
#include "commap.h"

namespace ComLibSim
{

ComMap::ComMap (int nb_rates):
  m_map (nb_rates),
  m_nb_rates (nb_rates)
{
}

ComMap::ComMap (const ComMap& map):
  m_nb_rates (map.m_nb_rates),
  m_map (map.m_map)
{
}

ComMap::~ComMap ()
{
}

unsigned int ComMap::get_nb_rates () const
{
  return m_nb_rates;
}

void ComMap::set_nb_rates (unsigned int nb_rates)
{
  if (static_cast<unsigned int> (m_map.size ()) > nb_rates)
    m_map.erase (m_map.begin () + nb_rates, m_map.end ());

  m_nb_rates = nb_rates;
}

void ComMap::set (const ComMap& map)
{
  m_nb_rates = map.m_nb_rates;
  m_map = map.m_map;
}

}
