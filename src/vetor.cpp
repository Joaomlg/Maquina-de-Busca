#include "vetor.h"
#include <cmath>

Vetor::Vetor(){
    map <string, float> element;
    modulo = 0;
    somatorio = 0;
}

void Vetor::insert_coord(string word, float value){
    element.insert( pair<string, float >(word, value) );
    somatorio = somatorio + value*value;
    modulo = sqrt(somatorio);
}

float Vetor::operator*(Vetor x){
    float escalar=0;
    int aux;
    map <string, float> ::iterator primeiro,segundo;
    
    for(primeiro = this->element.begin(); primeiro!=this->element.end(); primeiro++){
        for(segundo = x.element.begin(); segundo!=x.element.end(); segundo++){
            if(primeiro->first==segundo->first){
                escalar = escalar + primeiro->second*segundo->second;
            }
        }
    }
    
    return escalar;
}

float Vetor::module(){
    // float modulo;
    // map <string, float> ::iterator it;
    // for(it = this->element.begin(); it!=this->element.end(); it++){
    //     modulo = modulo + it->second*it->second;
    // }
    // modulo = sqrt(somatorio);
    return modulo;
}