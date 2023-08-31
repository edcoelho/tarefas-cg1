CXXFLAGS = -pedantic-errors
LDLIBS = -lGL -lglut -lGLEW -lm

# Diretórios importantes
SRCDIR = src/
INCLUDEDIR = include/
BUILDDIR = build/

ALL: main

debug: CXXFLAGS += -g
debug: clean main

build_dir:
	if [ ! -d "build" ]; then mkdir "build"; fi

main: build_dir main.o
	$(CXX) $(CXXFLAGS) $(BUILDDIR)*.o -o main $(LDLIBS)

main.o: RaioRayCasting.o Esfera.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)main.cpp -o $(BUILDDIR)main.o

RaioRayCasting.o: utils.o Esfera.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)RaioRayCasting.cpp -o $(BUILDDIR)RaioRayCasting.o

Esfera.o: utils.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)Esfera.cpp -o $(BUILDDIR)Esfera.o

utils.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)utils.cpp -o $(BUILDDIR)utils.o

clean:
	rm -rf $(BUILDDIR) main