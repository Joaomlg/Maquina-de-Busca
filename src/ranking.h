#ifndef RANKING
#define RANKING

#include <string>
#include <iostream>

using namespace std;

class ranking_cell {
    private:
        string key;
        float value;

    public:
        // Cria nova calula do tipo chave-valor para rankeamento
        ranking_cell(string key, float value);

        // Compara valores, verifica se é menor
        bool operator<(const ranking_cell& other) const;

        // Printa chave do ranking na tela
        friend ostream& operator<<(ostream& os, const ranking_cell& ct);
};

#endif