#include "vetor.h"
#include <cmath>

Vetor::Vetor(){
    map <string, float> element;
}

void Vetor::insert_coord(string word, float value){
    element.insert( pair<string, float >(word, value) );
}

float Vetor::operator*(Vetor x){
    float escalar=0;
    int aux;
    map <string, float> ::iterator primeiro,segundo;
    if(this->element.size()==x.element.size() || this->element.size()>x.element.size()){
        segundo=x.element.begin();
        for(primeiro=this->element.begin(); primeiro!=this->element.end(); primeiro++){
            escalar += primeiro->second*segundo->second;
            segundo++;
        }
    } else{
        primeiro=this->element.begin();
        for(segundo=x.element.begin(); segundo!=x.element.end(); segundo++){
            escalar += primeiro->second*segundo->second;
            primeiro++;
        }
    }
    return escalar;
}

float Vetor::module(){
    float modulo;
    map <string, float> ::iterator it;
    for(it = this->element.begin(); it!=this->element.end(); it++){
        modulo += it->second*it->second;
    }
    return sqrt(modulo);
}