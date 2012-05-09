#ifndef __H_ACCUMULATOR__
#define __H_ACCUMULATOR__

#include "equipament.h"

namespace ComLibSim
{

class Accumulator: public Equipament
{
private:
  unsigned int m_capacity;
  unsigned int m_amount_data;

public:
  Accumulator ();
  Accumulator (unsigned int capacity, unsigned int amount_data);
  Accumulator (const Accumulator& accumulator);
  virtual ~Accumulator ();

  virtual unsigned int get_capacity    () const;
  virtual unsigned int get_amount_data () const;

  virtual void set_capacity    (unsigned int capacity);
  virtual void set_amount_data (unsigned int amount_data);

  virtual bool is_empty () const;
  virtual bool is_full  () const;
  virtual void fill     ();

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;
};

}

#endif
