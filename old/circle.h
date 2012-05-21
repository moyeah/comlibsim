#ifndef __H_CIRCLE__
#define __H_CIRCLE__

#define PI 3.14159

#include "figure.h"

namespace ComLibSim
{

class Circle: public Figure
{
private:
  Point  m_center;
  double m_radius;

public:
  Circle ();
  Circle (const Point& center, double radius);
  Circle (const Circle& circle);
  virtual ~Circle ();

  virtual Circle& operator = (const Circle& circle);

  virtual bool operator == (const Circle& circle) const;
  virtual bool operator != (const Circle& circle) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const Circle& circle);

  virtual Point&  get_center ();
  virtual double  get_radius () const;
  virtual Circle& get ();

  virtual void set_center (const Point& center);
  virtual void set_radius (double radius);
  virtual void set        (const Point& center, double radius);
  virtual void set        (const Circle& circle);

  virtual void copy (const Circle& circle);

  virtual double area     () const;
  virtual bool   contains (const Point& point) const;
  virtual bool   contains (const Circle& circle) const;

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;
};

}

#endif
