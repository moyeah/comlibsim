#ifndef __H_SENSOR__
#define __H_SENSOR__

namespace ComLibSim
{

class Sensor: public Equipament
{
private:
  Position    m_position;
  Accumulator m_accumulator;
  ComMap      m_com_map;

public:
  Sensor ();
  Sensor (const Position& position,
          const Accumulator& accumulator,
          const ComMap& com_map);
  virtual ~Sensor ();

  virtual Position&    get_position    ();
  virtual Accumulator& get_accumulator ();
  virtual ComMap&      get_com_map     ();
  virtual Sensor&      get             ();

  virtual void set_position    (const Position& position);
  virtual void set_accumulator (const Accumulator& accumulator);
  virtual void set_com_map     (const ComMap& com_map);
  virtual void set             (const Position& position,
                                const Accumulator& accumulator,
                                const ComMap& com_map);
};

}

#endif
