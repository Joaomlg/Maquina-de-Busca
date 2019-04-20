#include "word_treatment.h"

std::vector <std::string> split(std::string& phrase, std::string separator) {

}

void treat(std::string& word) {
    for(int i=0; i<word.length(); i++) {
        char c = word[i];

        // Remove special char
        if(!isalnum(c)) {
            word.erase(i, 1);
        }

        // Remove accent
        // [...]

        // Transform to lowercase
        if(isupper(c)) {
            word[i] = tolower(c);
        }
    }
}