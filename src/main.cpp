#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string>
#include <vector>
#include <cmath>

#include "word_treatment.h"
#include "Vocabulary.h"
#include "list_database.h"
#include "vetor.h"

#define DOC_QUERY ""

using namespace std;

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

    Vetor words_coord;
    map <string, Vetor> docs_weight;
    float value;
    
    for(int i=0; i<file_list.size(); i++) {
        ifstream file(file_list[i]);
        if(file.is_open()) {
            string word;
            while(file >> word) {
                treat(word);
                value = vocabulary.tf(word,file_list[i])*vocabulary.idf(word);
                words_coord.insert_coord(word, value);
            }
            docs_weight[file_list[i]]=words_coord;
            file.close();
        }
    }

    string query;
    cout << "O que deseja pesquisar?\n> ";
    cin >> query;

    vector <string> query_words = split(query, " ");

    Vocabulary query_vocabulary(query_words.size());

    for(int i=0; i<query_words.size(); i++) {
        treat(query_words[i]);
        query_vocabulary.insert(query_words[i], DOC_QUERY);
    }

    Vetor vector_query;
    for(string word_query:query_words){
        value = query_vocabulary.tf(word_query, DOC_QUERY)*query_vocabulary.idf(word_query);
        vector_query.insert_coord(word_query,value);
    }

    return 0;
}
