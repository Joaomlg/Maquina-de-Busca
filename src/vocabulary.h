#ifndef VOCABULARY_H
#define VOCABULARY_H

#include <string>
#include <map>
#include <cmath>
#include <vector>

#include "multiset.h"

using namespace std;

class Vocabulary {
    private:
        map <string, my_multiset <std::string>> dict;
        int n_doc;

    public:
        // Cria vocabulario vazio
        Vocabulary(int n_doc);

        // Testa se palavra esta contida no vocabulario
        bool contains(string word);

        // Insere nova palavra no vocabulario (ou nova ocorrencia de palavra ja existente)
        void insert(string word, string doc);

        // Remove palavra do vocabulario
        void remove(string word);

        // Retorna vetor de palavras contidas no vocabulário
        vector <string> get_words();

        // Calcula frequencia do termo no documento
        float tf(string word, string doc);

        // Calcula inverso da frequencia da palavra nos documentos
        float idf(string word);

        //
        ~Vocabulary();

        friend class Teste;
};

#endif