CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb


all: bin/main bin/teste

clean:
	rm -rf bin/* .vscode/ipch

run: bin/main
	clear
	./bin/main

teste: bin/teste
	clear
	./bin/teste

bin/fila.o: src/fila.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/main: bin/fila.o src/main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/teste: bin/fila.o src/teste.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@
	