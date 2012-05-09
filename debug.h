#ifndef __H_DEBUG__
#define __H_DEBUG__

namespace ComLibSim
{

class Debug
{
protected:
  double m_x;
  double m_y;

public:
  Point ();
  Point (double x, double y);
  Point (const Point& point);
  virtual ~Point ();

  virtual double get_x () const;
  virtual double get_y () const;

  virtual void set_x (double x);
  virtual void set_y (double y);
  virtual void set   (double x, double y);
  virtual void set   (const Point& point);

  virtual double distance_to (double x, double y) const;
  virtual double distance_to (const Point& point) const;
};

}

#endif
