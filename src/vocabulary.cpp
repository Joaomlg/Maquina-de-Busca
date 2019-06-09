#include "vocabulary.h"
#include "multiset.h"

Vocabulary::Vocabulary (int ndoc) {
    map <string, my_multiset <std::string>> dict;
    this->n_doc = ndoc;
}

bool Vocabulary::contains (string word){
    map<string, my_multiset<string>>::iterator it = dict.find(word);
    if(it->first == word) return true;
    else return false;
}

void Vocabulary::insert (string word, string doc) {
    if (contains(word))
        dict[word].insert(doc);
    else {
        dict[word] = my_multiset<string>();
        dict[word].insert(doc);
    }
    
}

void Vocabulary::remove (string word) {
    map <string, my_multiset<std::string>> :: iterator it;
    it = dict.find(word);
    dict.erase(it);
}

float Vocabulary::tf (string word, string doc){
    return dict[word].count(doc);
}

float Vocabulary::idf (string word) {
    float count_words = dict[word].count_different();
    return log(n_doc/count_words);
}

Vocabulary::~Vocabulary() {
    dict.clear();
}