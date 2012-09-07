#include "comlibsim.hpp"

#define OUTPUT_MAIN_FILE "log/simulation.log"
#define CLUSTER_LOG_FILE "log/cluster.log"
#define SENSORS_MAP_FILE "log/sensors.map"
#define PRINT_SIM_APP    "gnuplot"

const char *argp_program_version     = "ComLibSim v0.0";
const char *argp_program_bug_address = "<da.arada@gmail.com>";

static char doc[]       = "Communication Library Simulator";
static char args_doc [] = "<filename>.xml";

static struct argp_option options[] = {
  {"verbose", 'v', 0,        0, "Verbose output"},
  {"step",    's', "NUMBER", 0, "Simulation step size [0.1]"},
  {"time",    't', "DOUBLE", 0, "Simulation time [10000]"},
  {"output",  'l', "FILE",   0, "Output main file [log/simulation.log]"},
  {"cluster", 'c', "FILE",   0, "Cluster log file [log/cluster.log]"},
  {"sensors", 'e', "FILE",   0, "Sensors map file [log/sensors.map]"},
  {"app",     'a', "FILE",   0, "App to print sim [gnuplot]"},
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
    case 's':
      arguments->step_size = strtod (arg, NULL);
      break;
    case 't':
      arguments->sim_time = strtod (arg, NULL);
      break;
    case 'l':
      arguments->output_file = arg;
      break;
    case 'c':
      arguments->cluster_log_file = arg;
      break;
    case 'e':
      arguments->sensors_map_file = arg;
      break;
    case 'a':
      arguments->print_sim_app = arg;
      break;
    case ARGP_KEY_ARG:
      if (state->arg_num >= 1)
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

int sim_main(const struct arguments *arguments);

int
main (int argc, char **argv)
{
  int nb_sensors;
  int status;

  // Arguments management
  struct arguments arguments;

  // Default values
  arguments.verbose          = 0;
  arguments.step_size        = 0.1;
  arguments.sim_time         = 10000;
  arguments.output_file      = (char *) OUTPUT_MAIN_FILE;
  arguments.cluster_log_file = (char *) CLUSTER_LOG_FILE;
  arguments.sensors_map_file = (char *) SENSORS_MAP_FILE;
  arguments.print_sim_app    = (char *) PRINT_SIM_APP;

  argp_parse (&argp, argc, argv, 0, 0, &arguments);

  // Run simulation
  nb_sensors = sim_main (&arguments);

  // Print simulation log files
  if (strcmp (arguments.print_sim_app, (char *) PRINT_SIM_APP) == 0)
  {
    char gnuplot_script[50];

    sprintf (gnuplot_script,
             "%s -p -e \"NbSensors=%d\" gnuplot/map.p",
             arguments.print_sim_app,
             nb_sensors);
    status = system (gnuplot_script);
  }

  return status;
}
