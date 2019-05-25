#include "similarity.h"

float similiaridade(Vetor doc, Vetor query){
    float sim, modD, modQ;
    modD = doc.module();
    modQ = query.module();
    sim = (doc*query)/(modD*modQ);
    return sim;
}

list <string> order(map<string, float> docs_simi){
    list <string> ordernado;
    list <float> organiza;
    vector <string> docs;
    map <float, vector<string>> simi_docs;
    map <float, vector<string>>::iterator it_sd;
    map <string, float>::iterator it_ds;
    it_sd = simi_docs.begin();
    for(it_ds=docs_simi.begin(); it_ds!=docs_simi.end(); it_ds++){
        //se estiver vazio
        if(docs_simi.find(it_ds->first)!=docs_simi.end()){
            docs.push_back(it_ds->first);
            simi_docs.insert(pair<float,vector<string>>(it_ds->second, docs));
            organiza.push_back(it_ds->second);
        } else {
            docs=it_sd->second;
            docs.push_back(it_ds->first);
            simi_docs.at(it_ds->second)=docs;
        }
        it_sd++;
        docs.clear();
    }

    organiza.sort();
    organiza.reverse();

    for(float similiaridade:organiza){
        docs = simi_docs[similiaridade];
        for(string name_doc:docs){
            ordernado.push_back(name_doc);
        }
    }

    return ordernado;
}