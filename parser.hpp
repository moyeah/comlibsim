
#ifndef __H_PARSER__
#define __H_PARSER__

#include <libxml++/libxml++.h>
#include <iostream>

#include "cluster.hpp"

namespace ComLibSim
{

class Parser: xmlpp::DomParser
{
public:
  Parser (std::string filepath = "cluster.xml");
  virtual ~Parser ();

  virtual bool check_parser () const;

  virtual int get_sensors (const xmlpp::Node* node,
                           Cluster& cluster
                           std::ostream output = std::cout) const;

  virtual int to_cluster (Cluster& cluster,
                          std::ostream& output = std::cout) const;

  virtual void write_indent (std::ostream& output = std::cout,
                             unsigned int indent = 0) const;
  virtual void write        (Glib::ustring& text,
                             std::ostream& output = std::cout) const;
  virtual void write_ln     (Glib::ustring& text,
                             std::ostream& output = std::cout) const;
};

}

#endif
