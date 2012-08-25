
#ifndef __H_PARSER__
#define __H_PARSER__

#include <libxml++/libxml++.h>
#include <iostream>

#include "cluster.hpp"

namespace ComLibSim
{

class Parser: xmlpp::DomParser
{
private:
  std::string m_filepath;

public:
  Parser (std::string filepath = "cluster.xml");
  virtual ~Parser ();

  virtual bool check_parser () const;

  virtual int get_node (const xmlpp::Node* node,
                        Cluster& cluster,
			unsigned int indent = 0,
                        std::ostream& output = std::cout) const;

  virtual int to_cluster (Cluster& cluster,
                          std::ostream& output = std::cout) const;

  virtual void write_indent (unsigned int indent = 0,
                             std::ostream& output = std::cout) const;
  virtual void write        (const Glib::ustring& text,
                             std::ostream& output = std::cout) const;
  virtual void write_ln     (const Glib::ustring& text,
                             std::ostream& output = std::cout) const;
};

}

#endif
