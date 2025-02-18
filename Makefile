BIN   = window
CC    = g++
FLAGS = -Iinclude -Wall -pedantic -std=c++17
LIBS  = -lGLEW -lglfw -lGL -lz
SRC   = glad.c window.cpp

all:
	$(CC) $(FLAGS) -o $(BIN) $(SRC) $(LIBS)

clean:
	rm -rf $(BIN)
