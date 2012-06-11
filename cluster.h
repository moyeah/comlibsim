#ifndef __H_CLUSTER__
#define __H_CLUSTER__

namespace ComLibSim
{

class Cluster
{
private:
  std::vector<Sensor> m_sensors;

public:
  Cluster (int nb = 0);
  virtual ~Cluster ();

  virtual void add (const Sensor& sensor);

  virtual Sensor&       closest (const Position& position);
  virtual const Sensor& closest (const Position& position) const;

  virtual void write (std::ostream& output = std::cout) const;
};

}

#endif
