/*
 *  comrate.hpp
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

#ifndef __H_COMRATE__
#define __H_COMRATE__

#include <cmath>
#include <iostream>
#include <iomanip>

#include "object.hpp"
#include "position.hpp"

namespace ComLibSim
{

class ComRate: public Object
{
private:
  const Position*     m_reference;
  double              m_max_rate;
  double              m_act_rate;
  static const double m_radius_low   = 20.0;
  static const double m_radius_high  = 60.0;

public:
  ComRate ();
  ComRate (const Position& reference,
           double max_rate,
           double act_rate = 0);
  ComRate (const ComRate& com_rate);
  virtual ~ComRate ();

  virtual Object* object () const;

  virtual bool operator == (const ComRate& com_rate) const;
  virtual bool operator != (const ComRate& com_rate) const;
  virtual bool operator >  (const ComRate& com_rate) const;
  virtual bool operator <  (const ComRate& com_rate) const;
  virtual bool operator >= (const ComRate& com_rate) const;
  virtual bool operator <= (const ComRate& com_rate) const;

  virtual void set_act_rate (double act_rate);
 
  virtual double get_max_rate () const;
  virtual double get_act_rate () const;

  virtual double rate_at (double distance) const;
  virtual double rate_at (const Position& position) const;

  virtual void write     (std::ostream& output = std::cout) const;
  virtual void write_ln  (std::ostream& output = std::cout) const;
  virtual void write_log (std::ostream& output = std::cout) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const ComRate& com_rate);
};

}

#endif
