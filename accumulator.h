#ifndef __H_ACCUMULATOR__
#define __H_ACCUMULATOR__

#include "equipament.h"

namespace ComLibSim
{

class Accumulator: public Equipament
{
private:
  unsigned int m_amount_data;

public:
  Accumulator ();
  Accumulator (unsigned int amount_data);
  Accumulator (const Accumulator& accumulator);
  virtual ~Accumulator ();

  virtual unsigned int get_amount_data () const;
  virtual Accumulator& get             ();

  virtual void set_amount_data (unsigned int amount_data);
  virtual void set             (const Accumulator& accumulator);

  virtual bool is_empty () const;

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;
};

}

#endif
