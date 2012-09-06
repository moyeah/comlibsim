/*
 *  comlibsim.hpp
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

#ifndef __H_COMLIBSIM__
#define __H_COMLIBSIM__

#include <iostream>
#include <stdlib.h>
#include <argp.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

struct arguments
{
  char    *cluster_xml_file[1];
  int      verbose;
  double   step_size;
  double   sim_time;
  char    *output_file;
  char    *cluster_log_file;
  char *sensors_map_file;
  char *print_sim_app;
};

#endif
