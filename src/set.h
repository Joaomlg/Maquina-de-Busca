#ifndef SET_H
#define SET_H

template <class type>
class Set {
    private:
        struct node;
        node* _end;
        int _size;

    public:
        // Cria um conjunto vazio
        Set();

        // Cria um conjunto contendo x
        Set(type x);

        // Cria um conjunto com os mesmos valores de x
        Set(const Set& x);

        // Testa se o conjunto é vazio
        bool empty() const;

        // Retorna tamanho do conjunto
        int size() const;

        // Testa se x pertence ao conjunto
        bool contains(type x) const;

        // Retorna numero de ocorrencias do elemento x no conjunto
        int count(type x) const;

        // Retorna numero de elementos diferentes no conjunto
        int count_different() const;

        // Insere elemento x no conjunto
        void insert(type x) const;

        // Remove elemento x do conjunto
        // Pre-condicao: o conjunto tem ao menos um elemento
        void remove(type x) const;

        // Retorna elemento do conjunto
        // Pre-condicao: o conjunto tem ao menos um elemento
        type get() const;

        // Retorna uniao entre *this e x
        Set union_2(const Set& x);
        Set union_2(type x);

        // Retorna intersecao entre *this e x
        Set intersection(const Set& x);
        Set intersection(type x);

        // Retorna diferenca entre *this e x
        Set operator-(const Set& x);
        Set operator-(type x);

        // Faz com que *this tenha os mesmos elementos de x
        void operator=(const Set& x);

        // Desaloca memoria alocada para o conjunto
        ~Set();
};

#endif