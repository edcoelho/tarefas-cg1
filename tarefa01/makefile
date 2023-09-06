CXXFLAGS = -pedantic-errors
LDLIBS = -lSDL2

# Diretórios importantes.
SRCDIR = src/
INCLUDEDIR = include/
BUILDDIR = build/

ALL: main

# Target para gerar executável para debugging.
debug: CXXFLAGS += -g
debug: clean main

# Target para criar o diretório build.
build_dir:
	if [ ! -d "$(BUILDDIR)" ]; then mkdir "$(BUILDDIR)"; fi

# Targets para compilação e ligação.
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

# Target para apagar objetos e executável.
clean:
	rm -rf $(BUILDDIR) main