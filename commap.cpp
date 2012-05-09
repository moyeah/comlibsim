#include <iostream>
#include <vector>

#include "position.h"
#include "circle.h"
#include "comrate.h"
#include "commap.h"

namespace ComLibSim
{

ComMap::ComMap ():
  m_map (0),
  m_nb_rates (0)
{
}

ComMap::ComMap (unsigned int nb_rates):
  m_map (nb_rates),
  m_nb_rates (nb_rates)
{
}

ComMap::ComMap (unsigned int nb_rates, const ComRate map[]):
  m_map (nb_rates),
  m_nb_rates (nb_rates)
{
  m_map.reserve (nb_rates);

  for (int i = 0; i < (int) nb_rates; i++)
    m_map.push_back (map[i]);
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
