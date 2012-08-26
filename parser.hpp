/*
 *  parser.hpp
 *
 *  Copyright (C) 2011-2012  Daniel Sousa   <da.arada@gmail.com>
 *  Copyright (C) 2011-2012  Jorge Estrela  <jes@isep.ipp.pt>
 *
 *  Autor:
 *    Daniel Sousa  <da.arada@gmail.com>
 *
 *  Orientador:
 *    Jorge Estrela  <jes@isep.ipp.pt>
 */

#ifndef __H_PARSER__
#define __H_PARSER__

#include <libxml++/libxml++.h>
#include <glibmm.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "cluster.hpp"

namespace ComLibSim
{

class Parser
{
private:
  std::string  m_filepath;

public:
  Parser (std::string filepath = "config/cluster.xml");
  virtual ~Parser ();

  virtual int to_cluster (Cluster& cluster,
                          std::ostream& output = std::cout) const;

  virtual void write        (const Glib::ustring& text,
                             std::ostream& output = std::cout) const;
  virtual void write_ln     (const Glib::ustring& text,
                             std::ostream& output = std::cout) const;
};

}

#endif
