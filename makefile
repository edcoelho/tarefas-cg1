SHELL := /bin/bash

CXXFLAGS := -pedantic-errors
LDLIBS := -lSDL2

# Diretórios importantes.
SRC_DIR := src/
INCLUDE_DIR := include/
BUILD_DIR := build/

# Lista de arquivos .cpp
SRC_FILES := $(shell find $(SRC_DIR) -name "*.cpp")

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
$(BUILD_DIR)main.o: $(SRC_DIR)main.cpp $(INCLUDE_DIR)utils/utils.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDE_DIR)%.hpp $(INCLUDE_DIR)utils/utils.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

# Target para criar o diretório build.
$(BUILD_DIR):
ifeq ($(wildcard $(BUILD_DIR)),)
    $(shell mkdir $(BUILD_DIR))
    $(shell find $(INCLUDE_DIR) -type d -exec mkdir -p "$(BUILD_DIR){}" \;)
    $(shell mv $(BUILD_DIR)$(INCLUDE_DIR)* $(BUILD_DIR) 2>/dev/null ; true) # "2>/dev/null" faz um possível erro do mv ser ignorado
    $(shell rm -r $(BUILD_DIR)$(INCLUDE_DIR))
endif

# Target para apagar objetos e executável.
clean:
	rm -rf $(BUILD_DIR) *.o main