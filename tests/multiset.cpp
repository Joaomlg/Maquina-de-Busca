#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include "../src/multiset.h"

using namespace std;

TEST_SUITE("Multiset") {
    TEST_CASE("count_different()") {
        Multiset<int> x;
        x.insert(1); x.insert(1); x.insert(1);
        x.insert(2); x.insert(2);
        x.insert(3);
        CHECK(x.size() == 6);
        CHECK(x.count(1) == 3);
        CHECK(x.count(3) == 1);
        CHECK(x.count_different() == 3);
    }
}