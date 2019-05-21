#ifndef SIMILARITY_H
#define SIMILARITY_H

#include <string>
#include <map>
#include "vetor.h"
#include <vector>
#include <list>

using namespace std;

//Calcula a similiaridade entre dois vetores
float similiaridade(Vetor doc, Vetor query);

//Insere Documento e Similiaridade em um map<string,float>
void inserir(map<string, float> docs_simi, string document, float sim);

//Ordena os documentos de um map de acordo com sua similiaridade
//Retorna uma list de string
list <string> order(map<string,float> docs_simi);

#endif