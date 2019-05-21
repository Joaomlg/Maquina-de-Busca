#include "similarity.h"

float similiaridade(Vetor doc, Vetor query){
    float sim;
    sim = (doc*query)/(doc.module()*query.module());
    return sim;
}

list <string> order(map<string, float> docs_simi){
    list <string> ordernado;
    map <float, vector<string>> simi_docs;
    map <string, float>::iterator it_sd;
    map <string, float>::iterator it_ds;
    for(it_ds=docs_simi.begin(); it_ds!=docs_simi.end(); it_ds++){
        
    }
}