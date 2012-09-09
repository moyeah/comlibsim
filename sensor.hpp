/*
 *  sensor.hpp
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

#ifndef __H_SENSOR__
#define __H_SENSOR__

#include <iostream>

#include "object.hpp"
#include "accumulator.hpp"
#include "comrate.hpp"
#include "position.hpp"

namespace ComLibSim
{

class Sensor: public Object
{
private:
  Accumulator m_accumulator;
  Position    m_position;
  ComRate     m_com_rate;
  std::string m_tag;
  double      m_rate;

public:
  Sensor (const Position& position,
          double max_rate,
          double data,
          const std::string& tag = NULL);
  Sensor (const Sensor& sensor);
  virtual ~Sensor ();

  virtual Object* object () const;

  virtual bool operator == (const Sensor& sensor) const;
  virtual bool operator != (const Sensor& sensor) const;

  virtual void data (double data, double time = 0.0);
  virtual void rate (double rate);

  virtual void get_xy (double *xy) const;

  virtual bool   is_empty    () const;
  virtual double data        () const;
  virtual double max_rate    () const;
  virtual double rate        () const;
  virtual double bandwidth   () const;
  virtual double rate_at     (const Position& position) const;
  virtual double distance_to (const Position& position) const;

  virtual void write                 (std::ostream& output = std::cout) const;
  virtual void write_ln              (std::ostream& output = std::cout) const;
  virtual void write_accumulator_log (std::ostream& output = std::cout) const;
  virtual void write_rate_log        (std::ostream& output = std::cout) const;
  virtual void write_map             (std::ostream& output = std::cout) const;
  virtual void write_tag             (std::ostream& output = std::cout) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const Sensor& sensor);
};

}

#endif
