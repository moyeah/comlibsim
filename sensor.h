#ifndef __H_SENSOR__
#define __H_SENSOR__

namespace ComLibSim
{

class Sensor: public Equipament
{
private:
  Position    m_position;
  Accumulator m_accumulator;
  ComRate     m_com_rate;

public:
  Sensor ();
  Sensor (const Position& position,
          const Accumulator& accumulator,
          const ComRate& com_rate);
  virtual ~Sensor ();

  virtual Position&    get_position    ();
  virtual Accumulator& get_accumulator ();
  virtual ComRate&     get_rate        ();
  virtual Sensor&      get             ();

  virtual void set_position    (const Position& position);
  virtual void set_accumulator (const Accumulator& accumulator);
  virtual void set_com_rate    (const ComRate& com_rate);
  virtual void set             (const Position& position,
                                const Accumulator& accumulator,
                                const ComRate& com_rate);
};

}

#endif
