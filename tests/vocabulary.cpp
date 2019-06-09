#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include "../src/Vocabulary.h"

using namespace std;

class Teste {
    public:
        static int dict_size(Vocabulary x) { return x.dict.size(); }
        static int n_doc(Vocabulary x) { return x.n_doc; }
        static map<string, my_multiset<string>> dict(Vocabulary x) { return x.dict; }
};

TEST_SUITE("Vocabulary") {
    TEST_CASE("Vocabulary(int n_doc)") {  
        Vocabulary v(1);
        CHECK(Teste::n_doc(v) == 1);
        CHECK(Teste::dict_size(v) == 0);
    }

    TEST_CASE("insert(string word, string doc)") {
        Vocabulary v(2);
        v.insert("teste", "doc1");
        v.insert("teste", "doc2");
        v.insert("teste", "doc2");
        v.insert("palavra", "doc1");

        REQUIRE(Teste::dict_size(v) == 2);

        my_multiset <string> expected;
        expected.insert("doc1");
        CHECK(Teste::dict(v)["palavra"] == expected);
        expected.insert("doc2");
        CHECK_FALSE(Teste::dict(v)["teste"] == expected);
        expected.insert("doc2");
        CHECK(Teste::dict(v)["teste"] == expected);
    }

    TEST_CASE("contains") {
        Vocabulary v(2);
        v.insert("teste", "doc1");
        v.insert("teste", "doc2");
        v.insert("palavra", "doc1");

        CHECK(v.contains("teste"));
        CHECK(v.contains("palavra"));
        CHECK_FALSE(v.contains("doc1"));
    }


    // TEST_CASE("remove") {

    // }

    TEST_CASE("tf") {
        Vocabulary v(2);
        v.insert("teste", "doc1");
        v.insert("teste", "doc2");
        v.insert("teste", "doc2");
        v.insert("palavra", "doc1");
        v.insert("palavra", "doc1");
        v.insert("palavra", "doc1");

        CHECK(v.tf("teste", "doc1") == 1);
        CHECK(v.tf("teste", "doc2") == 2);
        CHECK(v.tf("palavra", "doc1") == 3);
    }

    TEST_CASE("idf") {
        Vocabulary v(3);
        v.insert("teste", "doc1");
        v.insert("teste", "doc2");
        v.insert("teste", "doc2");
        v.insert("palavra", "doc1");
        v.insert("palavra", "doc1");
        v.insert("palavra", "doc1");
        v.insert("word", "doc2");

        CHECK(abs(v.idf("teste") - 0.405) < 0.001);
        CHECK(abs(v.idf("palavra") - 1.098) < 0.001);
        CHECK(abs(v.idf("word") - 1.098) < 0.001);
    }
}
