#include "word_treatment.h"

std::vector <std::string> split(std::string& phrase, std::string separator) {

}

void to_lowercase(std::string& word) {
    for(int i=0; i<word.length(); i++) {
        char c = word[i];
        if(isupper(c)) {
            word[i] = tolower(c);
        }
    }
}

void remove_special_char(std::string& text) {
    for(int i=0; i<text.length(); i++) {
        char c = text[i];
        if(!isalnum(c)) {
            text.erase(i, 1);
        }
    }
}

void remove_accent(std::string& text) {

}

void treat(std::string& word) {
    to_lowercase(word);
    remove_accent(word);
    remove_special_char(word);
}