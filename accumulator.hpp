/*
 *  accumulator.hpp
 *
 *  Copyright (C) 2011-2012  Daniel Sousa   <da.arada@gmail.com>
 *  Copyright (C) 2011-2012  Jorge Estrela  <jes@isep.ipp.pt>
 *
 *  Created by:
 *    Daniel Sousa  <da.arada@gmail.com>
 *
 *  Sponsor:
 *    Jorge Estrela  <jes@isep.ipp.pt>
 */

#ifndef __H_ACCUMULATOR__
#define __H_ACCUMULATOR__

#include <iostream>

#include "object.hpp"

namespace ComLibSim
{

class Accumulator: public Object 
{
private:
  double m_amount_data;

public:
  Accumulator ();
  Accumulator (double amount_data);
  Accumulator (const Accumulator& accumulator);
  virtual ~Accumulator ();

  virtual Object*      object     () const;
  virtual void         copy       (const Accumulator& accumulator);
  virtual Accumulator& operator = (const Accumulator& accumulator);

  virtual bool operator == (const Accumulator& accumulator) const;
  virtual bool operator != (const Accumulator& accumulator) const;
  virtual bool operator >  (const Accumulator& accumulator) const;
  virtual bool operator <  (const Accumulator& accumulator) const;
  virtual bool operator >= (const Accumulator& accumulator) const;
  virtual bool operator <= (const Accumulator& accumulator) const;

  virtual double get_amount_data () const;

  virtual void set_amount_data (double amount_data);

  virtual bool is_empty () const;

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const Accumulator& accumulator);
};

}

#endif
