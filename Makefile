CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic

BIN := bin
SIM := simulacion-registro-alumnos
SIM_SRC := $(wildcard $(SIM)/src/*.cpp)
SIM_INC := $(wildcard $(SIM)/include/*.h)

.PHONY: all practica1 simulacion run-practica1 run-simulacion clean

all: practica1 simulacion

practica1: $(BIN)/division_segura
simulacion: $(BIN)/registro_alumnos

$(BIN)/division_segura: practica1-division-segura/division_segura.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN)/registro_alumnos: $(SIM_SRC) $(SIM_INC) | $(BIN)
	$(CXX) $(CXXFLAGS) -I$(SIM)/include $(SIM_SRC) -o $@

$(BIN):
	mkdir -p $(BIN)

run-practica1: practica1
	./$(BIN)/division_segura

run-simulacion: simulacion
	cd $(SIM) && ../$(BIN)/registro_alumnos

clean:
	rm -rf $(BIN)
