CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2 -Iinclude
SRC = src/main.cpp src/simulacion.cpp src/graficar.cpp src/animacion.cpp
OUT = bin/box1D

all: build run

build:
	mkdir -p bin results scripts
	$(CXX) $(SRC) $(CXXFLAGS) -o $(OUT)

run: build
	./$(OUT)

clean:
	rm -f bin/box1D results/* scripts/*.gp
