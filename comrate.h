#ifndef __H_COMRATE__
#define __H_COMRATE__

namespace ComLibSim
{

class Position;

class ComRate: public Object
{
private:
  const Position*     m_reference;
  double              m_max_rate;
  static const double m_radius_low  = 20.0;
  static const double m_radius_high = 80.0;

public:
  ComRate ();
  ComRate (const Position& reference, double max_rate);
  ComRate (const ComRate& com_rate);
  virtual ~ComRate ();

  virtual Object* object () const;

  virtual bool operator == (const ComRate& com_rate) const;
  virtual bool operator != (const ComRate& com_rate) const;
  virtual bool operator >  (const ComRate& com_rate) const;
  virtual bool operator <  (const ComRate& com_rate) const;
  virtual bool operator >= (const ComRate& com_rate) const;
  virtual bool operator <= (const ComRate& com_rate) const;

  virtual double get_max_rate () const;

  virtual double rate_at (double distance) const;
  virtual double rate_at (const Position& position) const;

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const ComRate& com_rate);
};

}

#endif
