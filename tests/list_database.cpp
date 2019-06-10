#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "../src/list_database.h"

TEST_CASE("requestArchievs()") {
    string pasta = "tests/database";
    vector <string> expected = {
        "tests/database/Subdatabase/doc3.txt", 
        "tests/database/Subdatabase/doc2.txt", 
        "tests/database/Subdatabase/dir/doc4.txt",
        "tests/database/doc1.txt"
    };

    vector <string> received = requestArchievs(pasta);
    
    REQUIRE(received.size() == expected.size());

    for(int i=0, j=0; i<expected.size(); i++, j++){
        CHECK(received[i] == expected[j]);
    }
}