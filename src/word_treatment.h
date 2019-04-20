#ifndef WORD_TREATMENT_H
#define WORD_TREATMENT_H

#include <vector>
#include <string>

// Função que separa frase em uma lista de substrings
std::vector <std::string> split(std::string& phrase, std::string separator);

// Função que trata palavra: remove acento, caracteres especiais e transforma para lowercase
void treat(std::string& word);

#endif