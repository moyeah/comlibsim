#ifndef __H_OBJECT__
#define __H_OBJECT__

namespace ComLibSim
{

class Object
{
public:
  virtual Object* object () const = 0;
  virtual ~Object () {};
};

}

#endif
