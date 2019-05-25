#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "../src/similarity.h"

using namespace std;

TEST_CASE("similiaridade(Vetor doc, Vetor query)") {
    Vetor doc, query;
    float sim, expected=0.262346354, histerese=0.0001;

    doc.insert_coord("ola",  0.4);
    doc.insert_coord("meu",  0.2);
    doc.insert_coord("nome", 0.3);
    doc.insert_coord("e",    0.5);
    doc.insert_coord("jason",0.9);

    query.insert_coord("ola",   0.1);
    query.insert_coord("mi",    0.9);
    query.insert_coord("nome",  0.7);
    query.insert_coord("es",    0.8);
    query.insert_coord("jason", 0.2);

    //doc.module() = 1.161895004
    //query.module() = 1.410673598
    //doc*query = 0.43
    //sim = 0.43/1.639054606 = 0.262346354

    sim = similiaridade(doc, query);

    CHECK(sim>=(expected-histerese));
    CHECK(sim<=(expected+histerese));

}