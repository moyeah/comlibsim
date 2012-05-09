#ifndef __H_POSITION__
#define __H_POSITION__

#include "point.h"

namespace ComLibSim
{

class Position: public Point
{
public:
  Position ();
  Position (double x, double y);
  Position (const Point& point);
  Position (const Position& position);
  virtual ~Position ();
};

}

#endif
