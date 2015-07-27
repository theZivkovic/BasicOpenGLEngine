PROGRAM  = engine
FILES 	 = main configuration shader \
		   program variable mesh sphere_mesh triangle_mesh \
		   camera light
CXX 	 = g++
CXXFLAGS = -g -Wall -I/usr/X11R6/include -I/usr/pkg/include -std=c++11
LDFLAGS  = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS	 = -lglut -lGLU -lGL -lGLEW -lSOIL -std=c++11


$(PROGRAM): $(patsubst %, %.o, $(FILES))
		$(CXX) $(LDFLAGS) -o $(PROGRAM) $(patsubst %, %.o, $(FILES)) $(LDLIBS)

.PHONY: beauty clean

beauty:
	-indent -kr -nut $(patsubst %, %.cpp, $(FILES)) $(patsubst %, %.hpp, $(filter-out main, $(FILES)))
	-rm *~ $(PROGRAM)

clean:
	-rm *.o $(PROGRAM)
