#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

#include "src/word_treatment.h"
#include "src/vocabulary.h"
#include "src/list_database.h"
#include "src/vector.h"
#include "src/ranking.h"

#define DOC_QUERY ""

using namespace std;

std::ostream& operator<< (std::ostream& os, const priority_queue<ranking_cell>& ct) {
  priority_queue <ranking_cell> x(ct);
  string chave;
  for(int i=0; i<x.size(); i++) {
    chave = x.top().chave();
    //std::cerr << chave << endl;
    os << chave << endl;
    x.pop();
  }
  return os;
}

int main() {
    vector <string> file_list = requestArchievs("database");

    Vocabulary vocabulary(file_list.size());

    for(int i=0; i<file_list.size(); i++) {
        ifstream file(file_list[i]);
        if(file.is_open()) {
            string word;
            while(file >> word) {
                treat(word);
                vocabulary.insert(word, file_list[i]);
            }
            file.close();
        } else {
            cout << "Erro ao tentar abrir arquivo: " << file_list[i] << endl;
            exit(1);
        }
    }

    vector <string> words_list = vocabulary.get_words();

    map <string, Vector> docs_coord;
    for(auto &doc: file_list) {
        Vector doc_vector;
        for(auto &word: words_list) {
            doc_vector.insert_coord(word, vocabulary.tf(word, doc) * vocabulary.idf(word));
        }
        docs_coord[doc] = doc_vector;
    }

    while(1) {
        string query;
        cout << "O que deseja pesquisar?\n> ";
        getline(cin, query);

        vector <string> query_words = split(query, " ");

        Vocabulary query_vocabulary(query_words.size());

        for(int i=0; i<query_words.size(); i++) {
            treat(query_words[i]);
            query_vocabulary.insert(query_words[i], DOC_QUERY);
        }

        map <string, Vector> query_coord;
        Vector query_vector;
        for(auto &word: words_list) {
            query_vector.insert_coord(word, query_vocabulary.tf(word, DOC_QUERY) * vocabulary.idf(word));
        }

        priority_queue <ranking_cell> ranking;
        for(auto &doc: file_list) {
            float similarity = docs_coord[doc].cos(query_vector);
            if(similarity > 0) {
                ranking.push(ranking_cell(doc, similarity));
            }
        }

        cout << ranking << endl;

        //for(int i=0; i<ranking.size(); i++) {
        //    cout << ranking.pop() << endl;
        //}
    }

    return 0;
}
