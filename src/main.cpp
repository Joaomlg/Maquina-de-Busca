#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string>
#include <vector>

#include "word_treatment.h"
#include "Vocabulary.h"
#include "list_database.h"
#include "vetor.h"

using namespace std;

int main() {

    /*
    ###########################################################################################
    ##################################### BANCO DE DADOS ######################################
    ###########################################################################################
    */

    vector <string> file_list = requestArchievs("database");

    Vocabulary inverted_index;

    for(int i=0; i<file_list.size(); i++) {
        ifstream file(file_list[i]);
        if(file.is_open()) {
            string word;
            while(file >> word) {
                treat(word);
                inverted_index.insert(word, file_list[i]);
            }
            file.close();
        } else {
            cout << "Erro ao tentar abrir arquivo: " << file_list[i] << endl;
            exit(1);
        }
    }

    /*
    ###########################################################################################
    ############################# GERAR COORDENADAS PARA DOC * PALAVRA ########################
    ###########################################################################################
    */

    Vetor words_coord;
    map <string, Vetor> docs_weight;
    float value;
    
    for(int i=0; i<file_list.size(); i++) {
        ifstream file(file_list[i]);
        if(file.is_open()) {
            string word;
            while(file >> word) {
                treat(word);
                value = inveted_index(word,document)*inverted_index(word);
                words_coord(word, value);
            }
            docs_weight[file_list[i]]=words_coord;
            file.close();
        }
    }

    /*
    ###########################################################################################
    ##################################### ENTRADA DO USUARIO ##################################
    ###########################################################################################
    */

    Vocabulary query_vocabulary;

    string query;
    cout << "O que deseja pesquisar?\n> ";
    cin >> query;

    vector <string> query_words = split(query, " ");
    for(int i=0; i<query_words.size(); i++) {
        treat(query_words[i]);
        query_vocabulary.insert(query_words[i], "");
    }

    /*
    ###########################################################################################
    ##################################### RANKEAR DOCUMENTOS ##################################
    ###########################################################################################
    */

    return 0;
}
