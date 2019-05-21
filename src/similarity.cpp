#include "similarity.h"

float similiaridade(Vetor doc, Vetor query){
    float sim;
    sim = (doc*query)/(doc.module()*query.module());
    return sim;
}

void inserir(map <string,float> docs_simi, string document, float sim){
    docs_simi.insert(pair<string, float>(document, sim));
}

list <string> order(map<string, float> docs_simi){
    list <string> ordernado;
    map <string, float>::interator it;
    for(it=docs_simi.begin(); it!=docs_simi.end(); i++){
        
    }
}