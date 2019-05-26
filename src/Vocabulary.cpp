#include <string>
#include <map>
#include <cmath>

#include "Vocabulary.h"
#include "multiset.h"

Vocabulary :: Vocabulary () {
    map <string, Multiset <std::string>> dict;
    int number_doc = 0;
}

bool Vocabulary :: contains (string word){
    for (map<string, Multiset<string>>::iterator it=dict.begin(); it!=dict.end(); ++it){
        if(it->first == "word") return 1;
        else return 0;
    }
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

