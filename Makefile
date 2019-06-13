CXX		  := g++
# CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb

all: tests/bin/list_database tests/bin/word_treatment tests/bin/multiset tests/bin/vector tests/bin/vocabulary maquina_de_busca # tests/bin/ranking

clean:
	rm -rf bin/* .vscode/ipch

# run: bin/main
# 	clear
# 	./bin/main

# teste: bin/teste_multiconjunto
# 	clear
# 	./bin/teste_multiconjunto

bin/list_database.o: src/list_database.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/word_treatment.o: src/word_treatment.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/multiset.o: src/multiset.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/vocabulary.o: src/vocabulary.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/vector.o: src/vector.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/ranking.o: src/ranking.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

tests/bin/list_database: bin/list_database.o tests/list_database.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

tests/bin/multiset: bin/multiset.o tests/multiset.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

# tests/bin/ranking: bin/ranking.o tests/ranking.cpp
# 	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

tests/bin/vector: bin/vector.o tests/vector.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

tests/bin/vocabulary: bin/vocabulary.o tests/vocabulary.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

tests/bin/word_treatment: bin/word_treatment.o tests/word_treatment.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

maquina_de_busca: bin/list_database.o bin/word_treatment.o bin/multiset.o bin/vocabulary.o bin/ranking.o bin/vector.o main.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@