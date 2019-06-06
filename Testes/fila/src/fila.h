#ifndef FILA_H
#define FILA_H

#include <string>

using std::string;

struct No;

class Fila {
 public:
  // Cria uma fila vazia.
  Fila();

  // Cria uma fila com os mesmos elementos de x (na mesma ordem).
  Fila(const Fila& x);

  // Testa se a fila está vazia.
  bool vazia() const;

  // Retorna o número de elementos na fila.
  int tamanho() const;
  
  // Retorna o primeiro elemento da fila.
  // PRECONDIÇÃO: A fila não pode estar vazia.
  string primeiro() const;

  // Insere um elemento no fim da fila.
  void Inserir(string s);

  // Retira o primeiro elemento da fila.
  // PRECONDIÇÃO: A fila não pode estar vazia.
  void RemoverPrimeiro();

  // Compara se *this tem os mesmos elementos que x (na mesma ordem)
  bool operator==(const Fila& x) const;

  // Faz *this ter os mesmos elementos que x (na mesma ordem).
  void operator=(const Fila& x);

  // Desaloca a memória alocada para a fila.
  ~Fila();

 private:
  No* fim_;  // Ponteiro para o sentinela da lista encadeada.
  int tamanho_;  // Número de elementos na fila;

  friend class Teste;
};

#endif  // FILA_H
