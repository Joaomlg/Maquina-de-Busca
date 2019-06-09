#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "../src/similarity.h"

using namespace std;

TEST_CASE("similiaridade(Vetor doc, Vetor query)") {
    Vetor doc, query;
    float sim, expected=0.571428571;

    doc.insert_coord("ola",  4);
    doc.insert_coord("meu",  5);
    doc.insert_coord("nome", 2);
    doc.insert_coord("jason",2);

    query.insert_coord("ola",   4);
    query.insert_coord("mi",    4);
    query.insert_coord("nome",  4);
    query.insert_coord("jason", 4);
    
    sim = similiaridade(doc, query);
    
    CHECK(doc.module()==7.0);
    CHECK(query.module()==8.0);
    CHECK((doc.module()*query.module())==56.0);
    CHECK((doc*query)==32.0);
    CHECK(((doc*query)/(doc.module()*query.module()))==expected);
    
    CHECK(sim==expected);
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