#ifndef __H_COMMAP__
#define __H_COMMAP__

#include "rate.h"

namespace ComLibSim
{

class ComMap: public Rate
{
private:
  std::vector<ComRate> m_rates;

  virtual void sort ();

public:
  ComMap (int nb_rates);
  ComMap (const ComMap& com_map);
  virtual ~ComMap ();

  virtual ComMap& operator = (const ComMap& com_map);

  virtual bool operator == (const ComMap& com_map) const;
  virtual bool operator != (const ComMap& com_map) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const ComMap& com_map);

  virtual ComMap& get (const ComMap& com_map);

  virtual void set (const ComMap& map);

  virtual void push (const ComRate& com_rate);

  virtual ComRate& pull (double rate);

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;
};

}

#endif
