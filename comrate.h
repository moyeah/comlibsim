#ifndef __H_COMRATE__
#define __H_COMRATE__

#include "rate.h"

namespace ComLibSim
{

class ComRate: public Rate
{
private:
  Circle m_circle;
  double m_rate;

public:
  ComRate ();
  ComRate (const Position& center, double radius, double rate);
  ComRate (const Circle& circle, double rate);
  ComRate (const ComRate& comrate);
  virtual ~ComRate ();

  virtual Circle&  get_circle ();
  virtual double   get_rate   () const;
  virtual ComRate& get       ();

  virtual void set_circle (const Circle& circle);
  virtual void set_rate   (double rate);
  virtual void set        (const Position& center, double radius, double rate);
  virtual void set        (const Circle& circle, double rate);
  virtual void set        (const ComRate& comrate);

  virtual double get_rate_at (const Position& position) const;

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;
};

}

#endif
