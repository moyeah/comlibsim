#ifndef __H_SENSOR__
#define __H_SENSOR__

namespace ComLibSim
{

class Sensor: public Equipament
{
private:
  Position    m_position;
  Accumulator m_accumulator;
  RateMap     m_rate_map;

public:
  Sensor ();
  Sensor (const Position& position,
          const Accumulator& accumulator,
          const RateMap& rate_map);
  virtual ~Sensor ();

  virtual Position&    get_position    ();
  virtual Accumulator& get_accumulator ();
  virtual RateMap&     get_rate_map    ();

  virtual void set_position    (const Position& position);
  virtual void set_accumulator (const Accumulator& accumulator);
  virtual void set_rate_map    (const RateMap& rate_map);
};

}

#endif
