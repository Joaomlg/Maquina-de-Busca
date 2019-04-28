#ifndef LIST_H
#define LIST_H

template <class type>
class List {
    private:
        type* _elements;
        int _size;
        int _capacity;

        // Altera tamanho da lista
        // Pre-condicao: new_size >= _size
        void resize(int new_size);

    public:
        // Cria lista vazia
        List();

        // Cria lista contendo os mesmos elementos de x
        List(const List& x);

        // Testa se lista vazia
        bool empty() const;

        // Retorna tamanho da lista
        int size() const;

        // Insere novo elemento no final da lista
        void append(type x);

        // Remove elemento da lista
        // void remove(int index) const;
        // void remove(type element) const;

        // Avalia se *this contem os mesmos elementos de x
        bool operator==(const List& x) const;

        // Faz com que *this tenha os mesmos elementos de x
        void operator=(const File& x) const;

        // Retorna elemento contido no respectivo indice
        type& operator[](const int index);

        // Desaloca memoria alocada pela lista
        ~List();
};

#endif