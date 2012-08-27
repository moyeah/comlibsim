/*
 *  parser.cpp
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

#include "parser.hpp"

namespace ComLibSim
{

Parser::Parser (std::string filepath):
  m_filepath (filepath)
{
}

Parser::~Parser ()
{
}

int Parser::to_cluster (Cluster& cluster,
		        std::ostream& output) const
{

  static int nb_sensors_imported = 0;

  #ifdef LIBXMLCPP_EXCEPTIONS_ENABLE
  try
  {
  #endif
  xmlpp::DomParser parser (m_filepath, false);
  if (parser)
  {
    const xmlpp::Node* root_node = parser.get_document ()->get_root_node ();

    xmlpp::Node::NodeList sensors_list =
                            root_node->get_children ("Sensor");

    xmlpp::Node::NodeList::iterator sensor_iter;
    for (sensor_iter = sensors_list.begin ();
         sensor_iter != sensors_list.end ();
         sensor_iter++)
    {
      const xmlpp::Element* sensor_element =
                              dynamic_cast<const xmlpp::Element*>(*sensor_iter);

      double x = Glib::Ascii::strtod (
                   sensor_element->get_attribute_value ("x"));
      double y = Glib::Ascii::strtod (
                   sensor_element->get_attribute_value ("y"));
      double max_rate = Glib::Ascii::strtod (
                          sensor_element->get_attribute_value ("max_rate"));
      double data = Glib::Ascii::strtod (
                      sensor_element->get_attribute_value ("data"));

      cluster.add (Sensor (Position (x, y), max_rate, data));

      nb_sensors_imported++;
    }
  }
  #ifdef LIBXMLCPP_EXCEPTIONS_ENABLE
  }
  catch (const std::exception& ex)
  {
    std::cout << "Exception caught: " << ex.what () << std::endl;
    return -1;
  }
  #endif

  if (nb_sensors_imported > 0)
  {
    std::ostringstream total_sensors;
    total_sensors << nb_sensors_imported;
    this->write_ln ("Imported " +
                    total_sensors.str() +
                    " sensors from file \"" +
                    m_filepath + "\"", output);
  }
  else
    this->write_ln ("No sensors imported from file \"" +
                    m_filepath + "\"", output);

  return nb_sensors_imported;
}

void Parser::write (const Glib::ustring& text, std::ostream& output) const
{
  output << text;
}

void Parser::write_ln (const Glib::ustring& text, std::ostream& output) const
{
  this->write (text, output);
  output << std::endl;
}

}
