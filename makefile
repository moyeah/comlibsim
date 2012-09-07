##
 #  makefile
 #
 #  Copyright (C) 2011-2012  Daniel Sousa   <da.arada@gmail.com>
 #  Copyright (C) 2011-2012  Jorge Estrela  <jes@isep.ipp.pt>
 #
 #  Created by:
 #    Daniel Sousa  <da.arada@gmail.com>
 #
 #  Sponsor:
 #    Jorge Estrela  <jes@isep.ipp.pt>
 ##

CC         = g++
CFLAGS     = -Wall -g
LDFLAGS    =
LIBS       =
PKG_CONFIG = `pkg-config libxml++-2.6 --cflags --libs`
OBJS       = $(SRCS:.cpp=.o)
PROG       = comlibsim
SRCS       = accumulator.cpp \
             comrate.cpp \
             position.cpp \
             sensor.cpp \
             cluster.cpp \
             parser.cpp \
             sim/sim_model.cpp \
             sim/ode_solvers.cpp \
             sim/sim_main.cpp \
             comlibsim.cpp

all: $(SRCS) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LIBS) $(PKG_CONFIG)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(LIBS) $(PKG_CONFIG)

clean:
	rm -rf *.o *.out *~ sim/*.o sim/*.out sim/*~ log/*~ config/*~ \
	  gnuplot/*~ $(PROG)
