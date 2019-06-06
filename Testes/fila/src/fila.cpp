#include "fila.h"

using std::string;

struct No {
  string valor;
  No* esq;
  No* dir;
  No() {
    valor = "";
    esq = dir = nullptr;
  }
  No(string v, No* e, No* d) {
    valor = v;
    esq = e;
    dir = d;
  }
};

Fila::Fila() {
  tamanho_ = 0;
  fim_ = new No();
  fim_->esq = fim_->dir = fim_;
}

Fila::Fila(const Fila& x) : Fila() {
  *this = x;
}

bool Fila::vazia() const {
  return (tamanho_ == 0);
}

int Fila::tamanho() const {
  return tamanho_;
}
  
string Fila::primeiro() const {
  return fim_->dir->valor;
}

void Fila::Inserir(string s) {
  No* ultimo = fim_->esq;
  fim_->esq = ultimo->dir = new No(s, ultimo, fim_);
  tamanho_++;
}

void Fila::RemoverPrimeiro() {
  No* primeiro = fim_->dir;
  No* segundo = primeiro->dir;
  fim_->dir = segundo;
  segundo->esq = fim_;
  delete primeiro;
  tamanho_--;
}

void Fila::operator=(const Fila& x) {
  // Apaga todos os elementos de *this.
  while(!this->vazia()) {
    this->RemoverPrimeiro();
  }
  // insere todos os elementos de x em *this.
  for (No* i = x.fim_->dir; i != x.fim_; i = i->dir) {
    this->Inserir(i->valor);
  }
}

bool Fila::operator==(const Fila& x) const {
  if (this->tamanho() != x.tamanho()) {
    return false;
  } else {
    // Itera sobre dois ponteiros simultaneamente.
    for (No* i = fim_->dir, *j = x.fim_->dir;
         i != this->fim_ && j != x.fim_; 
         i = i->dir, j = j->dir) {
      if (i->valor != j->valor) {
        return false;
      }
    }
    return true;
  }
}

Fila::~Fila() {
  // Apaga todos os elementos de *this.
  while(!vazia()) {
    RemoverPrimeiro();
  }
  // Libera a memória do sentinela.
  delete fim_;
}