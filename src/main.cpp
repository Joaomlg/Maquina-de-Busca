#include <iostream>
#include <fstream>

#include "word_treatment.h"

#include <vector>  // Desenvolver estrutura de dados do vector posteriormente

using namespace std;

int main() {
    // Implementar função para identificar arquivos no database
    vector <string> file_list = {"../database/d1.txt", "../database/d2.txt", "../database/d3.txt"};

    for(int i=0; i<file_list.size(); i++) {
        ifstream file(file_list[i]);
        if(file.is_open()) {
            string word;
            while(file >> word) {
                treat(word);
            }
            file.close();
        } else {
            cout << "Erro ao tentar abrir arquivo: " << file_list[i] << endl;
            exit(1);
        }
    }

    return 0;
}