CXXFLAGS = -pedantic-errors
LDLIBS = -lSDL2

# Diretórios importantes.
SRCDIR = src/
INCLUDEDIR = include/
BUILDDIR = build/

# Lista de arquivos de objetos
OBJS = $(BUILDDIR)main.o $(BUILDDIR)RaioRayCasting.o $(BUILDDIR)Esfera.o

ALL: build_dir main

# Target para gerar executável para debugging.
debug: CXXFLAGS += -g
debug: clean ALL

# Targets para compilação e ligação.
main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDLIBS)

$(BUILDDIR)main.o: $(SRCDIR)main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)%.o: $(SRCDIR)%.cpp $(INCLUDEDIR)%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target para criar o diretório build.
build_dir:
	if [ ! -d "$(BUILDDIR)" ]; then mkdir "$(BUILDDIR)"; fi

# Target para apagar objetos e executável.
clean:
	rm -rf $(BUILDDIR) main