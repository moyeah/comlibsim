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

  virtual ComRate& operator = (const ComRate& comrate);

  virtual bool operator == (const ComRate& comrate) const;
  virtual bool operator != (const ComRate& comrate) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const ComRate comrate);

  virtual Circle&  get_circle ();
  virtual double   get_rate   () const;
  virtual ComRate& get        ();

  virtual void set_circle (const Circle& circle);
  virtual void set_rate   (double rate);
  virtual void set        (const Position& center,
                           double radius,
                           double rate);
  virtual void set        (const Circle& circle, double rate);
  virtual void set        (const ComRate& comrate);

  virtual void copy (const ComRate& comrate);

  virtual double rate_at (const Position& position) const;
  virtual double rate_at (const Circle& circle) const;

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;
};

}

#endif
