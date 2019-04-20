#ifndef WORD_TREATMENT_H
#define WORD_TREATMENT_H

#include <vector>
#include <string>

// Função que separa frase em uma lista de substrings
std::vector <std::string> split(std::string& phrase, std::string separator);

// Função que transforma string para lowercase
void to_lowercase(std::string& word);

// Função que remove caracteres especiais da string
void remove_special_char(std::string& text);

// Função que remove acentos dos caracteres no texto
void remove_accent(std::string& text);

// Função que trata palavra (remove acento, caracteres especiais e transforma para lowercase)
void treat(std::string& word);

#endif