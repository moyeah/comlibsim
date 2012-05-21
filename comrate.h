#ifndef __H_COMRATE__
#define __H_COMRATE__

#include "rate.h"

namespace ComLibSim
{

class ComRate: public Rate
{
private:
  const Position*     m_reference;
  static const double m_radius_low  = 20.0;
  static const double m_radius_high = 80.0;

public:
  ComRate ();
  ComRate (const Position& reference);
  virtual ~ComRate ();

  friend std::ostream& operator << (std::ostream& output,
                                    const ComRate comrate);

  virtual const Position& get_reference () const;
  virtual ComRate&        get           ();

  virtual void set_reference (const Position& reference);
//  virtual void set           (const ComRate& comrate);

//  virtual void copy (const ComRate& comrate);

  virtual double rate_at (double distance) const;
  virtual double rate_at (const Position& position) const;

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;
};

}

#endif
