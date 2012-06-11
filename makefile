CC=g++
CFLAGS=-Wall
LIBS=
SRCS= accumulator.cpp \
      comrate.cpp \
      position.cpp \
      sensor.cpp \
      cluster.cpp \
      test/utils.cpp \
      test/test_accumulator.cpp \
      test/test_comrate.cpp \
      test/test_position.cpp \
      test/test_sensor.cpp \
      test/test_cluster.cpp \
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
