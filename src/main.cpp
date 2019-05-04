#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string>
#include <vector>

#include "word_treatment.h"
#include "Vocabulary.h"
#include "list_database.h"

using namespace std;

int main() {
    Vocabulary vocabulary;

    // Implementar função para identificar arquivos no database
    vector <string> file_list = {"../database/d1.txt", "../database/d2.txt", "../database/d3.txt"};

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

    // =============================================================================================
    Vocabulary query_vocabulary;

    string query;
    cout << "O que deseja pesquisar?\n> ";
    cin >> query;

    vector <string> query_words = split(query, " ");
    for(int i=0; i<query_words.size(); i++) {
        treat(query_words[i]);
        query_vocabulary.insert(query_words[i], "");
    }

    return 0;
}
