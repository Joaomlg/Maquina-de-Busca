#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include "../src/word_treatment.h"

using namespace std;

TEST_CASE("split") {
    vector <string> expected = {"teste", "123", "456"};
    CHECK(split("teste 123 456", " ") == expected);
}

TEST_CASE("treat") {
    string a = "aBcDe";
    treat(a);
    CHECK(a == "abcde");
    string b = "t3st3_tre@t!";
    treat(b);
    CHECK(b == "t3st3tret");
    // string c = "ácêñtò";
    // treat(c);
    // CHECK(c == "acento");
}
