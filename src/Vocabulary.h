#ifndef VOCABULARY_H
#define VOCABULARY_H

#include <string>
#include <map>

#include "multiset.h"

class Vocabulary {
    private:
        map <string, Multiset<std::string>> dict;
        int ndoc;

    public:
        // Cria vocabulario vazio
        Vocabulary(int n_doc);

        // Testa se palavra esta contida no vocabulario
        bool contains(string word);

        // Insere nova palavra no vocabulario (ou nova ocorrencia de palavra ja existente)
        void insert(string word, string doc);

        // Remove palavra do vocabulario
        void remove(string word);

        // Calcula frequencia do termo no documento
        float tf(string word, string doc);

        // Calcula inverso da frequencia da palavra nos documentos
        float idf(string word);

        //
        ~Vocabulary();

};

#endif