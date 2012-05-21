#ifndef __H_COMMAP__
#define __H_COMMAP__

#include "rate.h"

namespace ComLibSim
{

class ComMap: public Rate
{
private:
  std::vector<ComRate> m_com_map;

public:
  ComMap ();
  explicit ComMap (int nb_rates = 1);
  ComMap (const ComMap& com_map);
  virtual ~ComMap ();

  virtual ComMap& operator = (const ComMap& com_map);

  friend std::ostream& operator << (std::ostream& output,
                                    const ComMap& com_map);

  virtual ComMap& get (const ComMap& com_map);

  virtual void set (const ComMap& com_map);

  virtual void copy (const ComMap& com_map);

  virtual void push (const ComRate& com_rate);

  virtual void sort ();

  virtual const_iterator begin () const;
  virtual const_iterator end   () const;

  virtual int    nb_rates () const;
  virtual double min      () const;
  virtual double max      () const;
  virtual double avg      () const;

  virtual void print (std::ostream& output = std::cout) const;
};

}

#endif
