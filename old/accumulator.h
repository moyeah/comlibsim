#ifndef __H_ACCUMULATOR__
#define __H_ACCUMULATOR__

#include "equipament.h"

namespace ComLibSim
{

class Accumulator: public Equipament
{
protected:
  std::vector<char> m_registers;
  unsigned int      m_capacity;

public:
  Accumulator ();
  explicit Accumulator (unsigned int capacity);
  Accumulator (const Accumulator& accumulator);
  virtual ~Accumulator ();

  virtual unsigned int get_capacity () const;

  virtual void set_capacity (unsigned int capacity);

  virtual bool is_empty () const;
  virtual bool is_full  () const;

  virtual void fill_seq  ();
  virtual void fill_seq  (unsigned int nb_registers);
  virtual void fill_rand ();
  virtual void fill_rand (unsigned int nb_registers);

  virtual unsigned int get_amount_data () const;

  virtual void print (std::ostream& output = std::cout) const;
};

}

#endif
