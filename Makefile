CXX		  := g++
# CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb

all: tests/bin/list_database tests/bin/multiset tests/bin/vetor tests/bin/vocabulary tests/bin/similarity 

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

bin/vetor.o: src/vetor.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/similarity.o: src/similarity.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

tests/bin/list_database: bin/list_database.o tests/list_database.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

tests/bin/multiset: bin/multiset.o tests/multiset.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

tests/bin/similarity: bin/similarity.o tests/similarity.cpp bin/vetor.o
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

tests/bin/vetor: bin/vetor.o tests/vetor.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

tests/bin/vocabulary: bin/vocabulary.o tests/vocabulary.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

tests/bin/word_treatment: bin/word_treatment.o tests/word_treatment.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@
