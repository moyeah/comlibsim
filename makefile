CC=g++
CFLAGS=-Wall
LIBS=
SRCS= object.cpp figure.cpp rate.cpp equipament.cpp \
      point.cpp \
      position.cpp \
      comrate.cpp \
      accumulator.cpp \
      sensor.cpp \
      test/test_point.cpp \
      test/test_position.cpp \
      test/test_comrate.cpp \
      test/utils.cpp \
      test/main.cpp
OBJS=$(SRCS:.cpp=.o)
PROG=comlibsim

all: $(SRCS) $(PROG) clean

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(LIBS)

clean:
	rm -rf *.o *.out test/*.o test/*.out
