BIN   = window
CC    = g++
FLAGS = -Iinclude -Iheader -Ishaders -Wno-unused-variable -Wall -pedantic -std=c++17
FLAGS_OSX = -Iinclude -I/opt/homebrew/include -Iheader -Wall -pedantic -std=c++17
LIBS  = -lGLEW -lglfw -lGL -lz -lm
LIBS_OSX  = -L/opt/homebrew/lib -lglfw
SRC   = src/glad.c src/*.cpp

all:
	$(CC) $(FLAGS) -o $(BIN) $(SRC) $(LIBS) && ./window
osx:
	$(CC) $(FLAGS_OSX) -o $(BIN) $(SRC) $(LIBS_OSX) && ./window
clean:
	rm -rf $(BIN)
