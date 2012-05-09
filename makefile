CC=g++
CFLAGS=-Wall
LIBS=
SRCS= object.cpp figure.cpp rate.cpp equipament.cpp \
      point.cpp circle.cpp \
      position.cpp \
      comrate.cpp commap.cpp\
      accumulator.cpp \
      sensor.cpp \
      main.cpp
OBJS=$(SRCS:.cpp=.o)
PROG=comlibsim

all: $(SRCS) $(PROG) clean

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(LIBS)

clean:
	rm -rf *.o *.out
