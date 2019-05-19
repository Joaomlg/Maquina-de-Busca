#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define _GLIBCXX_USE_CXX11_ABI 0

#include "../include/doctest.h"

#include "../src/list_database.h"

using namespace std;

TEST_CASE("requestArchievs()") {
    vector <string> expected = {"baseTeste1.txt", "baseTeste2.txt", "baseTeste3.txt"};
    string pasta = "teste/database";
    CHECK(requestArchievs(pasta) == expected);
}