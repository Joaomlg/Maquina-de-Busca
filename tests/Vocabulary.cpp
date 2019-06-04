#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "../src/Vocabulary.h"

using namespace std;

TEST_SUITE("Vocabulary") {
    TEST_CASE("Funcoes da classe Vocabulary") {  
        Vocabulary teste;
        //20_newsgroups\rec.sport.baseball\102588
        
        CHECK(teste.contains("sarcasm") == true);       //testa a função contains

        teste.insert("default_word", "102588");
        CHECK(teste.contains("default_word") == true);      //testa a função insert

        teste.remove("default_word");
        CHECK(teste.contains("default_word") == false);     //testa a função remove

        CHECK(teste.tf("sarcasm", "102588") == 1);      //testa a função tf
    }
}
