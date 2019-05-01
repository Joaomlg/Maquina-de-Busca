#include "word_treatment.h"

List <std::string> split(const std::string& phrase, const std::string separator) {
    List <std::string> list;
    std::string aux = "";
    for(int i = 0; i < phrase.length(); i++) {
        std::string c = std::string(1, phrase[i]);
        if(c != separator) {
            aux += c;
            if(i != phrase.length() -1)
                continue;
        }
        list.append(aux);
        aux.clear();
    }
    return list;
}

void treat(std::string& word) {
    for(int i=0; i<word.length(); i++) {
        char c = word[i];

        // Remove special char
        if(!isalnum(c)) {
            word.erase(i, 1);
        }

        // Transform to lowercase
        if(isupper(c)) {
            word[i] = tolower(c);
        }
    }

    // Remove accent
    // std::map <std::string, std::string> normalize = { {"á", "a"}, {"à", "a"}, {"ä", "a"}, {"ã", "a"}, {"â", "a"}, 
    //                                                   {"ç", "c"}, {"ĉ", "c"}, 
    //                                                   {"é", "e"}, {"è", "e"}, {"ë", "e"}, {"ẽ", "e"}, {"ê", "e"}, 
    //                                                   {"í", "i"}, {"ì", "i"}, {"ï", "i"}, {"ĩ", "i"}, {"î", "i"}, 
    //                                                   {"ñ", "n"}, 
    //                                                   {"ó", "o"}, {"ò", "o"}, {"ö", "o"}, {"õ", "o"}, {"ô", "o"}, 
    //                                                   {"ú", "u"}, {"ù", "u"}, {"ü", "u"}, {"ũ", "u"}, {"û", "u"}, 
    //                                                   {"ý", "y"}, {"ỳ", "y"}, {"ÿ", "y"}, {"ỹ", "y"}, {"ŷ", "y"} };

    // for(std::map<std::string, std::string>::iterator it=normalize.begin(); it!=normalize.end(); it++) {        
    //     std::size_t found = word.find(it->first);
    //     while(found != std::string::npos) {
    //         word.replace(found, it->first.length(), it->second);
    //         found = word.find(it->first);
    //     }
    // }
}