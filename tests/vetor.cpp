#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "../src/vetor.h"

using namespace std;

TEST_SUITE("Vetor") {
    TEST_CASE("module()") {
        Vetor vet, vet2;
        float mod1 = 0.6, mod2 = 1, mod3=7;
        vet.insert_coord("ola",0.4);
        vet.insert_coord("google", 0.2);
        vet.insert_coord("documento", 0.4);

        CHECK(vet.module()==mod1);

        vet.insert_coord("palavra", 0.8);

        CHECK(vet.module()==mod2);

        vet2.insert_coord("legal",4);
        vet2.insert_coord("bacana",5);
        vet2.insert_coord("testando",2);
        vet2.insert_coord("isso",2);

        CHECK(vet2.module()==mod3);
    }

    TEST_CASE("operator*(Vetor x)"){
        Vetor vetA, vetB;
        float result, expected=0.28, histerese=0.0001;

        vetA.insert_coord("ola",0.6);
        vetA.insert_coord("documento", 0.4);
        vetB.insert_coord("documento",0.4);
        vetA.insert_coord("cachorro",0.9);
        vetB.insert_coord("arbitrario", 0.5);
        vetB.insert_coord("ola", 0.2);

        result = vetA*vetB;
        CHECK(result >= (expected-histerese));
        CHECK(result <= (expected+histerese));
    }
}