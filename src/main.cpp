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
                value = inverted_index.tf(word,file_list[i])*inverted_index.idf(word);
                words_coord.insert_coord(word, value);
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
    
    //gerar coordenada da entrada
    Vetor vector_query;
    for(string word_query:query_words){
        value = query_vocabulary.tf(word_query,"")*query_vocabulary.idf(word_query);
        vector_query.insert_coord(word_query,value);
    }


    return 0;
}
