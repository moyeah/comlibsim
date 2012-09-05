#include <iostream>
#include <stdlib.h>
#include <argp.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "sim/sim_main.hpp"

#define CLUSTER_LOG_FILE "log/cluster.log"
#define SENSORS_LOG_FILE "log/sensors.log"
#define PRINT_SIM_APP    "octave"

const char *argp_program_version     = "ComLibSim v0.0";
const char *argp_program_bug_address = "<da.arada@gmail.com>";

static char doc[]       = "Communication Library Simulator";
static char args_doc [] = "<filename>.xml";

static struct argp_option options[] = {
  {"verbose", 'v', 0,      0, "Verbose output"},
  {"cluster", 'c', "FILE", 0, "Cluster log file"},
  {"sensors", 's', "FILE", 0, "Sensors log file"},
  {"app",     'a', "FILE", 0, "Application to print simulation"},
  {0}
};

static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = (struct arguments*) state->input;

  switch (key)
  {
    case 'v':
      arguments->verbose = 1;
      break;
    case 'c':
      arguments->cluster_log_file = arg;
      break;
    case 's':
      arguments->sensors_log_file = arg;
      break;
    case 'a':
      arguments->print_sim_app = arg;
      break;
    case ARGP_KEY_ARG:
      if (state->arg_num >= 4)
        argp_usage (state);
      arguments->cluster_xml_file[state->arg_num] = arg;
      break;
    case ARGP_KEY_END:
      if (state->arg_num < 1)
        argp_usage (state);
      break;
    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc};

int
main (int argc, char **argv)
{
  // Arguments management
  struct arguments arguments;

  // Default values
  arguments.verbose          = 0;
  arguments.cluster_log_file = (char *) CLUSTER_LOG_FILE;
  arguments.sensors_log_file = (char *) SENSORS_LOG_FILE;
  arguments.print_sim_app    = (char *) PRINT_SIM_APP;

  argp_parse (&argp, argc, argv, 0, 0, &arguments);


  // Start simulation process
  pid_t sim_pid;
  int   process_status;

  sim_pid = fork ();
  if (sim_pid == 0)
  {
    sim_main (&arguments);
  }
  else if (sim_pid < 0)
    process_status = -1;
  else 
    if (waitpid (sim_pid, &process_status, 0) != sim_pid)
      process_status = -1;

  return process_status;
}
