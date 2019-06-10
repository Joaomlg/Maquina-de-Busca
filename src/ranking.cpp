#include "ranking.h"

using namespace std;

ranking_cell::ranking_cell(string key, float value) {
    this->key = key;
    this->value = value;
}

bool ranking_cell::operator<(const ranking_cell& other) const {
    return (this->value < other.value);
}

ostream& operator<<(ostream& os, const ranking_cell& ct) {
    os << ct.key;
    return os;
}