CXXFLAGS := -pedantic-errors
LDLIBS := -lSDL2

# Diretórios importantes.
SRC_DIR := src/
INCLUDE_DIR := include/
BUILD_DIR := build/

# Lista de arquivos .cpp
SRC_FILES := $(wildcard $(SRC_DIR)*.cpp)

# Lista de arquivos .o
OBJ_FILES := $(patsubst $(SRC_DIR)%.cpp, $(BUILD_DIR)%.o, $(SRC_FILES))

ALL: $(BUILD_DIR) main

# Target para gerar executável para debugging.
debug: CXXFLAGS += -g
debug: clean ALL

# Target para ligação.
main: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@ $(LDLIBS)

# Targets para compilação.
$(BUILD_DIR)main.o: $(SRC_DIR)main.cpp $(INCLUDE_DIR)utils.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDE_DIR)%.hpp $(INCLUDE_DIR)utils.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target para criar o diretório build.
$(BUILD_DIR):
	if [ ! -d "$(BUILD_DIR)" ]; then mkdir "$(BUILD_DIR)"; fi

# Target para apagar objetos e executável.
clean:
	rm -rf $(BUILD_DIR) *.o main