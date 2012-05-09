#ifndef __H_COMMAP__
#define __H_COMMAP__

#include "rate.h"

namespace ComLibSim
{

class ComMap: public Rate
{
private:
  unsigned int         m_nb_rates;
  std::vector<ComRate> m_map;

public:
  ComMap ();
  explicit ComMap (unsigned int nb_rates);
  ComMap (unsigned int nb_rates, const ComRate map[]);
  ComMap (const ComMap& map);
  virtual ~ComMap ();

  virtual unsigned int get_nb_rates () const;

  virtual void set_nb_rates (unsigned int nb_rates);
  virtual void set (const ComMap& map);
};

}

#endif
