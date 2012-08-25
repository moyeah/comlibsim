CC=g++
CFLAGS=-Wall -g
LIBS=
PKG_CONFIG=`pkg-config libxml++-2.6 --cflags --libs`
SRCS= accumulator.cpp \
      comrate.cpp \
      position.cpp \
      sensor.cpp \
      cluster.cpp \
      parser.cpp \
      test2/sim_model.cpp \
      test2/ode_solvers.cpp \
      test2/sim_main.cpp
#      test/utils.cpp \
      test/test_accumulator.cpp \
      test/test_comrate.cpp \
      test/test_position.cpp \
      test/test_sensor.cpp \
      test/test_cluster.cpp \
      test/main.cpp 
OBJS=$(SRCS:.cpp=.o)
PROG=comlibsim

all: $(SRCS) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LIBS) $(PKG_CONFIG)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(LIBS) $(PKG_CONFIG)

clean:
	rm -rf *.o *.out test/*.o test/*.out test2/*.o test2/*.out $(PROG)
