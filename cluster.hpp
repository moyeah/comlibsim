/*
 *  cluster.hpp
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

#ifndef __H_CLUSTER__
#define __H_CLUSTER__

#include <iostream>
#include <vector>

#include "object.hpp"
#include "accumulator.hpp"
#include "comrate.hpp"
#include "position.hpp"
#include "sensor.hpp"

namespace ComLibSim
{

class Cluster
{
private:
  std::vector<Sensor> m_sensors;
  std::vector<Sensor> m_sensors_int;  // Copy of sensors vector to integrate

  int    m_nb_act_sensors; // Nb of sensors to connect (selected)
  double m_act_bandwidth;  // Bandwidth used by sensors (selected)
  bool   m_scheduling;     // Need or not scheduling

  // To integrate
  int    m_nb_act_sensors_int; // Nb of sensors to connect (selected)
  double m_act_bandwidth_int;  // Bandwidth used by sensors (selected)
  bool   m_scheduling_int;     // Need or not scheduling

public:
  class ComMap: public std::vector<std::vector<Sensor>::iterator>
  {
  public:
    double select (std::vector<Sensor>& sensors,
                   const Position& position);

    void write (std::ostream& output = std::cout) const;
  };

  Cluster (int nb = 0);
  virtual ~Cluster ();

  virtual int    nb_act_sensors () const;
  virtual double act_bandwidth  () const;
  virtual bool   scheduling     () const;
  virtual int    nb_sensors     () const;

  virtual void add (const Sensor& sensor);

  virtual void init_int ();
  virtual void copy_int ();

  virtual void get_data     (double *data) const;
  virtual void get_data_int (double *data) const;
  virtual void get_rate     (double *rate) const;
  virtual void get_rate_int (double *rate,
                             const double *position,
                             double agv_bandwidth);

  virtual void set_data     (double *data);
  virtual void set_data_int (const double *data);
  virtual void set_rate     (double *rate);

  virtual Sensor&       closest (const Position& position);
  virtual const Sensor& closest (const Position& position) const;

  virtual ComMap map     (const Position& position, double agv_bandwidth);
  virtual ComMap map_int (const Position& position, double agv_bandwidth);

  virtual void write                    (std::ostream& output = std::cout) const;
  virtual void write_accumulator_log    (std::ostream& output = std::cout) const;
  virtual void write_accumulator_log_ln (double t,
                                         std::ostream& output = std::cout) const;
  virtual void write_rate_log           (std::ostream& output = std::cout) const;
  virtual void write_rate_log_ln        (double t,
                                         std::ostream& output = std::cout) const;
  virtual void write_map                (std::ostream& output = std::cout) const;
};

}

#endif
