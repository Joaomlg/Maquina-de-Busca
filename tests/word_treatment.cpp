#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include "../src/word_treatment.h"
#include "../src/List.h"

using namespace std;

TEST_CASE("split") {
    List <string> expected;
    expected.append("teste");
    expected.append("123");
    expected.append("456");
    CHECK(split("teste 123 456", " ") == expected);
}

TEST_CASE("treat") {
    string a = "aBcDe";
    string b = "t3st3_tre@t!";
    string c = "ácêñtò";
    treat(a);
    treat(b);
    treat(c);
    CHECK(a == "abcde");
    CHECK(b == "t3st3tret");
    CHECK(c == "acento");
}
