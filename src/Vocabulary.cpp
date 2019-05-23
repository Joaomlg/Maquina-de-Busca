#include <string>
#include <map>
#include <cmath>

#include "multiset.h"

Vocabulary::Vocabulary () {
    map <string, Multiset <std::string>> dict;
    int number_doc = 0;
}

bool Vocabulary :: contains (string word){
    return (dict.find("word"))
}

void Vocabulary :: insert (string word, string doc) {
        dict["word"] = Multiset.insert("doc");
}

void Vocabulary :: remove (string word) {
    map <string, Multiset <std::string>> :: iterator it;
    it = dict.find("word");
    dict.erase(it);
}

float Vocabulary :: tf (string word, string doc){
    return dict["word"].count("doc");
}

float Vocabulary :: idf (string word) {
    float count_words = dict["word"].count_different();
    return log(number_doc/count_words);
}

Vocabulary :: ~Vocabulary() {
   delete dict;
}

};

