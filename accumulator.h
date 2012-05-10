#ifndef __H_ACCUMULATOR__
#define __H_ACCUMULATOR__

#include "equipament.h"

namespace ComLibSim
{

class Accumulator: public Equipament
{
private:
  int m_amount_data;

public:
  Accumulator ();
  Accumulator (int amount_data);
  Accumulator (const Accumulator& accumulator);
  virtual ~Accumulator ();

  virtual Accumulator& operator = (const Accumulator& accumulator);

  virtual bool operator == (const Accumulator& accumulator) const;
  virtual bool operator != (const Accumulator& accumulator) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const Accumulator& accumulator);

  virtual int          get_amount_data () const;
  virtual Accumulator& get             ();

  virtual void set_amount_data (int amount_data);
  virtual void set             (const Accumulator& accumulator);

  virtual void copy (const Accumulator& accumulator);

  virtual bool is_empty () const;

  virtual void download (double rate); 

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;
};

}

#endif
