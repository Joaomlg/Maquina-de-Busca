#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "../src/similarity.h"

using namespace std;

TEST_CASE("similiaridade(Vetor doc, Vetor query)") {
    Vetor doc, query;
    float sim, expected, histerese=0.0001, vsf, tnc, result;

    expected = ((0.2*0.2)+(0.2*0.2)+(0.2*0.2))/(sqrt((0.2*0.2)+(0.2*0.2)+
    (0.2*0.2)+(0.5*0.5)+(0.2*0.2))*sqrt((0.2*0.2)+(0.2*0.2)+(0.2*0.2)+(0.9*0.9)+(0.8*0.8)));

    doc.insert_coord("ola",  0.2);
    doc.insert_coord("meu",  0.2);
    doc.insert_coord("nome", 0.2);
    doc.insert_coord("e",    0.5);
    doc.insert_coord("jason",0.2);

    query.insert_coord("ola",   0.2);
    query.insert_coord("mi",    0.9);
    query.insert_coord("nome",  0.2);
    query.insert_coord("es",    0.8);
    query.insert_coord("jason", 0.2);
    
    sim = similiaridade(doc, query);

    CHECK(sim>=(expected-histerese));
    CHECK(sim<=(expected+histerese));

}

TEST_CASE("order(map<string, float> docs_simi)") {
    map<string, float> docs_simi;
    docs_simi["doc1.txt"] = 0.30;
    docs_simi["doc2.txt"] = 0.90;
    docs_simi["doc3.txt"] = 0.98;
    docs_simi["doc4.txt"] = 0.20;
    docs_simi["doc5.txt"] = 0.66;
    docs_simi["doc6.txt"] = 0.44;

    list <string> docs, expected;
    docs = order(docs_simi);

    expected = {"doc3.txt","doc2.txt","doc5.txt","doc6.txt","doc1.txt","doc4.txt"};

    CHECK(docs==expected);
}