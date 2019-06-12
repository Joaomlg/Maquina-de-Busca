#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "../src/list_database.h"
#include <set>

TEST_CASE("requestArchievs()") {
    string pasta = "tests/database";
    set <string> expected = {
        "tests/database/Subdatabase/doc3.txt", 
        "tests/database/Subdatabase/doc2.txt", 
        "tests/database/Subdatabase/dir/doc4.txt",
        "tests/database/doc1.txt"
    };

    vector <string> received = requestArchievs(pasta);
    
    REQUIRE(received.size() == expected.size());

    for(auto &f: received){
        CHECK(expected.find(f) != expected.end());
    }
}