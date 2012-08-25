#include "parser.hpp"

namespace ComLibSim
{

Parser::Parser (std::string filepath)
{
  this->set_substitute_entities ();
  this->parse_file (filepath);    
}

Parser::~Parser ()
{
}

bool Parser::check_parser () const
{
  if (this)
    return true;

  return false;
}

int Parser::get_sensors (const xmlpp::Node* node, Cluster& cluster) const
{
  const xmlpp::ContentNode* content_node =
                         dynamic_cast<const xmlpp::ContentNode*>(node);
  const xmlpp::TextNode* text_node =
                         dynamic_cast<const xmlpp::TextNode*>(node);
  const xmlpp::CommentNode* comment_node =
                         dynamic_cast<const xmlpp::CommentNode*>(node);

  if (text_node && text_node->is_white_space ())
    return;

  const Glib::ustring node_name = node->get_name ();

  if (!text_node && !comment_node && !node_name.empty ())
  {
  }
}

int Parser::to_cluster (Cluster& cluster, std::ostream& output) const
{
  int nb_sensors_added = 0;

  const xmlpp:Node* root_node = this->get_document ()->get_root_node ();

  this->get_sensors (const xmlpp::Node* root_node, Cluster& cluster);

  nb_sensors_added++:

  return nb_sensors_added;
}

void Parser::write_indent (std::ostream& output, unsigned int indent) const
{
  for (unsigned int i = 0; i < indent; ++i)
    output << " ";
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
