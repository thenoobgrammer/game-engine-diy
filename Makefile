BIN   = window
CC    = g++
FLAGS = -Iinclude -Wall -pedantic -std=c++17
FLAGS_OSX = -Iinclude -I/opt/homebrew/include -Wall -pedantic -std=c++17
LIBS  = -lGLEW -lglfw3 -lGL -lz
LIBS_OSX  = -L/opt/homebrew/lib -lglfw
SRC   = glad.c window.cpp

all:
	$(CC) $(FLAGS) -o $(BIN) $(SRC) $(LIBS)
osx:
	$(CC) $(FLAGS_OSX) -o $(BIN) $(SRC) $(LIBS_OSX)
clean:
	rm -rf $(BIN)
