#ifndef __H_POINT__
#define __H_POINT__

#include "figure.h"

namespace ComLibSim
{

class Point: public Figure
{
private:
  double m_x;
  double m_y;

public:
  Point ();
  Point (double x, double y);
  Point (const Point& point);
  virtual ~Point ();

  virtual Point& operator = (const Point& point);

  virtual bool operator == (const Point& point) const;
  virtual bool operator != (const Point& point) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const Point& point);

  virtual double get_x () const;
  virtual double get_y () const;
  virtual Point& get   ();

  virtual void set_x (double x);
  virtual void set_y (double y);
  virtual void set   (double x, double y);
  virtual void set   (const Point& point);

  virtual void copy (const Point& point);

  virtual double distance_to (double x, double y) const;
  virtual double distance_to (const Point& point) const;

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;
};

}

#endif
