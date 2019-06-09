#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "../src/list_database.h"

using namespace std;

TEST_CASE("requestArchievs()") {
    string pasta = "tests/database";
    vector <string> expected = {"baseTeste1.txt", "baseTeste2.txt", "baseTeste3.txt"};
    int checar=0;
    vector <string> received = requestArchievs(pasta);
    for(int i=0; i<expected.size(); i++){
        for(int j=0; j<received.size(); j++){
            if(expected[i]==received[j])
                checar++;
        }    
    }
    CHECK(checar==expected.size());
}