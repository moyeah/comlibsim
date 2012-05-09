#include <iostream>

#include "position.h"

namespace ComLibSim
{

Position::Position ():
  Point ()
{
}

Position::Position (double x, double y):
  Point (x, y)
{
}

Position::Position (const Point& point):
  Point (point)
{
}

Position::Position (const Position& position):
  Point (position)
{
}

Position::~Position ()
{
}

}
