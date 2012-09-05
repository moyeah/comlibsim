#ifndef SIM_MAIN_HPP_INCLUDED
#define SIM_MAIN_HPP_INCLUDED

struct arguments
{
  char *cluster_xml_file[1];
  int   verbose;
  char *cluster_log_file;
  char *sensors_log_file;
  char *print_sim_app;
};

int sim_main(const struct arguments *arguments);

#endif
