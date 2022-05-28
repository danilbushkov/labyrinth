



all: app



app: bin 	
	g++ ./src/main.cpp -o bin/main

check:
	valgrind --leak-check=yes ./bin/main

run: ./bin/main
	./bin/main


bin:
	mkdir bin/