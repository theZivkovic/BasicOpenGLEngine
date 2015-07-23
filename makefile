PROGRAM  = engine
CXX 	 = g++
CXXFLAGS = -g -Wall -I/usr/X11R6/include -I/usr/pkg/include -std=c++11
LDFLAGS  = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS	 = -lglut -lGLU -lGL -lGLEW -lSOIL -std=c++11

$(PROGRAM): main.o configuration.o shader.o program.o variable.o
		$(CXX) $(LDFLAGS) -o $(PROGRAM) main.o configuration.o shader.o program.o variable.o $(LDLIBS)

.PHONY: beauty clean

beauty:
	-indent -kr -nut main.c
	-rm *~ *BAK

clean:
	-rm *.o $(PROGRAM) *core
