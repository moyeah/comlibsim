#ifndef __H_SENSOR__
#define __H_SENSOR__

namespace ComLibSim
{

class Sensor: public Object
{
private:
  Accumulator m_accumulator;
  ComRate     m_com_rate;
  Position    m_position;

public:
  Sensor (const Position& position,
          double max_rate,
          double data);
  virtual ~Sensor ();

  virtual Object* object  () const;

  virtual void data (double data);

  virtual bool   is_empty    () const;
  virtual double data        () const;
  virtual double max_rate    () const;
  virtual double rate_at     (const Position& position) const;
  virtual double distance_to (const Position& position) const;

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const Sensor& sensor);
};

}

#endif
