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
#include <string.h>
#include <argp.h>

struct arguments
{
  char   *cluster_xml_file[1];
  int     verbose;
  double  step_size;
  double  sim_time;
  char   *simulation_log_file;
  char   *accumulator_log_file;
  char   *rate_log_file;
  char   *sensors_map_file;
  char   *print_sim_app;
};

#endif
