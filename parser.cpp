#include "parser.hpp"

namespace ComLibSim
{

Parser::Parser (std::string filepath):
  m_filepath (filepath)
{
  #ifdef LIBXMLCPP_EXCEPTIONS_ENABLE
  try
  {
  #endif

    this->set_substitute_entities ();
    this->parse_file (filepath);

  #ifdef LIBXMLCPP_EXCEPTIONS_ENABLE
  }
  catch (const std::exception& ex)
  {
    this->write_ln ("Exception caught: " + ex.what ());
  }
  #endif
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

int Parser::get_node (const xmlpp::Node* node,
                      Cluster& cluster,
		      unsigned int indent,
                      std::ostream& output) const
{
  const xmlpp::ContentNode* content_node =
                         dynamic_cast<const xmlpp::ContentNode*>(node);
  const xmlpp::TextNode* text_node =
                         dynamic_cast<const xmlpp::TextNode*>(node);
  const xmlpp::CommentNode* comment_node =
                         dynamic_cast<const xmlpp::CommentNode*>(node);

  if (text_node && text_node->is_white_space ())
    return -1;

  const Glib::ustring node_name = node->get_name ();

  if (!text_node && !comment_node && !node_name.empty ())
  {
    this->write_indent (indent, output);

    const Glib::ustring namespace_prefix = node->get_namespace_prefix ();

    this->write ("Node name = ", output);

    if (namespace_prefix.empty ())
      this->write_ln (node_name, output);
    else
      this->write_ln (namespace_prefix + ":" + node_name, output);
  }
  else if (text_node)
  {
    this->write_indent (indent, output);
    this->write_ln ("Text Node", output);
  }

  if (text_node)
  {
    this->write_indent (indent, output);
    this->write_ln ("text = \"" + text_node->get_content () + "\"", output);
  }
  else if (comment_node)
  {
    this->write_indent (indent, output);
    this->write_ln ("comment = " + comment_node->get_content (), output);
  }
  else if (content_node)
  {
    this->write_indent (indent, output);
    this->write_ln ("content = " + content_node->get_content (), output);
  }
  else if (const xmlpp::Element* element_node =
                                 dynamic_cast<const xmlpp::Element*>(node))
  {
    this->write_indent (indent, output);
    this->write_ln ("  line = " + node->get_line (), output);

    const xmlpp::Element::AttributeList& attributes =
                                         element_node->get_attributes ();

    xmlpp::Element::AttributeList::const_iterator iter;
    for (iter = attributes.begin ();
         iter != attributes.end ();
	 ++iter)
    {
      const xmlpp::Attribute* attribute = *iter;
      this->write_indent (indent, output);

      const Glib::ustring namespace_prefix =
                          attribute->get_namespace_prefix ();

      this->write ("  Attribute ", output);
      if (namespace_prefix.empty ())
        this->write_ln ("\"" +
                        attribute->get_name () +
                        "\" = " +
                        attribute->get_value (), output);
      else
        this->write_ln (namespace_prefix +
                        ":" +
                        attribute->get_name () +
                        " = " +
                        attribute->get_value (), output);
    }

    const xmlpp::Attribute* attribute = element_node->get_attribute ("title");
    if (attribute)
      this->write_ln ("Title \"" + attribute->get_value (), output);
  }

  if (!content_node)
  {
    xmlpp::Node::NodeList list = node->get_children ();

    for (xmlpp::Node::NodeList::iterator iter = list.begin ();
         iter != list.end ();
         ++iter)
    {
      this->get_node (*iter, cluster, indent + 2, output);
    }
  }

  return 0;
}

int Parser::to_cluster (Cluster& cluster,
		        std::ostream& output) const
{
  if (!this->check_parser ())
  {
    this->write_ln ("Error in the parser importing file: \"" +
                    m_filepath + "\"");
    return -1;
  }

  int nb_sensors_added = 0;

  const xmlpp::Node* root_node = this->get_document ()->get_root_node ();

  this->get_node (root_node, cluster, 0, output);

  nb_sensors_added++;

  return nb_sensors_added;
}

void Parser::write_indent (unsigned int indent, std::ostream& output) const
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
