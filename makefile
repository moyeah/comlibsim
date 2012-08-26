##
 #  makefile
 #
 #  Copyright (C) 2011-2012  Daniel Sousa   <da.arada@gmail.com>
 #  Copyright (C) 2011-2012  Jorge Estrela  <jes@isep.ipp.pt>
 #
 #  Autor:
 #    Daniel Sousa  <da.arada@gmail.com>
 #
 #  Orientador:
 #    Jorge Estrela  <jes@isep.ipp.pt>
 ##

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
      sim/sim_model.cpp \
      sim/ode_solvers.cpp \
      sim/sim_main.cpp
OBJS=$(SRCS:.cpp=.o)
PROG=comlibsim

all: $(SRCS) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LIBS) $(PKG_CONFIG)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(LIBS) $(PKG_CONFIG)

clean:
	rm -rf *.o *.out *~ sim/*.o sim/*.out sim/*~ log/*~ config/*~ $(PROG)
