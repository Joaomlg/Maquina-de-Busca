#include "vector.h"

Vector::Vector() {}

void Vector::insert_coord(string word, float value) {
    this->elements[word] = value;
}

float Vector::operator*(Vector x){
    float value = 0;
    if(this->elements.size() == x.elements.size()) {
        for(map <string, float>::iterator it=this->elements.begin(); it!=this->elements.end(); it++) {
            value += it->second * x.elements[it->first];
        }
    }
    return value;
}

float Vector::module(){
    float value = 0;
    for(auto &v: this->elements) {
        value += pow(v.second, 2);
    }
    return sqrt(value);
}

float Vector::cos(Vector x) {
    return (*this * x) / (this->module() * x.module());
}