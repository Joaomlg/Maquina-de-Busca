#ifndef SET_H
#define SET_H

#include <set>

template <class type>
class Multiset : public std::multiset<type> {
    public:
        // Retorna numero de elementos diferentes no conjunto
        int count_different() const {
            std::set<type> aux;
            for(typename std::multiset<type>::iterator it=this->begin(); it!=this->end(); it++) {
                aux.insert(*it);
            }
            return aux.size();
        }
};

#endif