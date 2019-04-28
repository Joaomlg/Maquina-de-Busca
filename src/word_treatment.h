#ifndef WORD_TREATMENT_H
#define WORD_TREATMENT_H

#include <string>
#include "List.h"

// Função que separa frase em uma lista de substrings
List <std::string> split(const std::string& phrase, const std::string separator);

// Função que trata palavra: remove acento, caracteres especiais e transforma para lowercase
void treat(std::string& word);

#endif