#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

#include "src/word_treatment.h"
#include "src/vocabulary.h"
#include "src/list_database.h"
#include "src/vector.h"
#include "src/ranking.h"

#define DOC_QUERY ""

using namespace std;

int main() {
    cout << "Iniciando maquina de busca..." << endl;

    vector <string> file_list = requestArchievs("database");

    Vocabulary vocabulary(file_list.size());

    for(int i=0; i<file_list.size(); i++) {
        cout << "\rLendo arquivos: " << i+1 << "/" << file_list.size();
        ifstream file(file_list[i]);
        if(file.is_open()) {
            string word;
            while(file >> word) {
                treat(word);
                vocabulary.insert(word, file_list[i]);
            }
            file.close();
        } else {
            cerr << "Erro ao tentar abrir arquivo: " << file_list[i] << endl;
        }
    }
    cout << endl;

    vector <string> words_list = vocabulary.get_words();

    cout << "Configurações finais..." << endl;
    map <string, Vector> docs_coord;
    for(int i=0; i<file_list.size(); i++) {
        cerr << "\rProcesso: " << (i+1)*100/file_list.size() << "%";
        string doc = file_list[i];
        Vector doc_vector;
        for(auto &word: words_list) {
            doc_vector.insert_coord(word, vocabulary.tf(word, doc) * vocabulary.idf(word));
        }
        docs_coord[doc] = doc_vector;
    }
    cout << endl;

    while(1) {
        string query;
        cout << endl << "O que deseja pesquisar?\n> ";
        getline(cin,query);
        cout << "BUSCANDO..." << endl;

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

        list <ranking_cell> ranking;
        for(auto &doc: file_list) {
            float similarity = docs_coord[doc].cos(query_vector);
            if(similarity > 0) {
                ranking.push_back(ranking_cell(doc, similarity));
            }
        }
        ranking.sort();

        cout << "Encontramos " << ranking.size() << " resultados para sua busca." << endl;

        if(ranking.size()) {
            cout << "Arquivos relacionados a sua pesquisa:" << endl;
            for(auto it=ranking.rbegin(); it!=ranking.rend(); it++) {
            cout << *it << endl;
            }
        }

        cout << "Para sair, basta apertar ctrl+c." << endl;

        /* 
        string continuar;
        do{
            cout << "Deseja realizar mais uma busca?(s/n)"<< endl << "> ";
            cin >> continuar;
        } while(continuar != "n" && continuar !="s");
        if (continuar=="n")
            break;
        */
    }

    return 0;
}
