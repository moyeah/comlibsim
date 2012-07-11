#ifndef __H_CLUSTER__
#define __H_CLUSTER__

namespace ComLibSim
{

class Cluster
{
private:
  std::vector<Sensor> m_sensors;

  int    m_nb_act_sensors; // Nb of sensors to connect (selected)
  double m_act_bandwidth;  // Bandwidth used by sensors (selected)
  bool   m_scheduling;     // Need or not scheduling

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

  virtual void get_data (double *data);
  virtual void get_rate (double *bandwidth);

  virtual void set_data (double *data);
  virtual void set_rate (double *bandwidth);

  virtual Sensor&       closest (const Position& position);
  virtual const Sensor& closest (const Position& position) const;

  virtual ComMap map (const Position& position, double agv_bandwidth);

  virtual void write (std::ostream& output = std::cout) const;
};

}

#endif
