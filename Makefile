

CFLAGS = -Wall -I./src

SRC_FILES = $(wildcard $(addsuffix /*.cpp, src))
OBJ_FILES = $(patsubst %,./obj/%,$(notdir $(SRC_FILES:%.cpp=%.o)))

all: ./bin/main



./bin/main: $(OBJ_FILES) | bin
	g++ $^ -o ./bin/main


vpath %.cpp ./src

./obj/%.o: %.cpp | obj
	g++ $(CFLAGS) -c $< -o $@



check:
	valgrind --leak-check=yes ./bin/main

run: ./bin/main
	./bin/main


bin:
	mkdir bin/

obj:
	mkdir obj/