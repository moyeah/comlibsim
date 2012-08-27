/*
 *  object.hpp
 *
 *  Copyright (C) 2011-2012  Daniel Sousa   <da.arada@gmail.com>
 *  Copyright (C) 2011-2012  Jorge Estrela  <jes@isep.ipp.pt>
 *
 *  Created by:
 *    Daniel Sousa  <da.arada@gmail.com>
 *
 *  Sponsor:
 *    Jorge Estrela  <jes@isep.ipp.pt>
 */

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
