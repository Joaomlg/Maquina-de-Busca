// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos - Coordenadas Euclidianas.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"
#include "../fila/src/fila.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <cmath>

using std::string;

struct No {
  string valor;
  No* esq;
  No* dir;
};

class Teste {
public:
  static No* fim(const Fila& c) {
    return  c.fim_;
  }
  static int tamanho(const Fila& c) {
    return  c.tamanho_;
  }
};

std::ostream& operator<< (std::ostream& out, const Fila& c) {
  Fila x(c);
  out << "[";
  while(x.tamanho() > 1){
    string e = x.primeiro();
    out << e << ", ";
    x.RemoverPrimeiro();
  }
  out << x.primeiro() << "]" << std::endl;
  return out;
}

TEST_SUITE("Fila") {  
  TEST_CASE("Fila()") {
    Fila f;
    CHECK(Teste::tamanho(f) == 0);
    CHECK(Teste::fim(f)->esq == Teste::fim(f));
    CHECK(Teste::fim(f)->dir == Teste::fim(f));

    Fila x;
    CHECK(x.tamanho() == 0);
  }

  TEST_CASE("Inserir(string)") {
    Fila f;
    f.Inserir("A");
    f.Inserir("C");
    f.Inserir("C");
    f.Inserir("B");
    REQUIRE(Teste::tamanho(f) == 4);
    CHECK(Teste::fim(f)->dir->valor == "A");
    CHECK(Teste::fim(f)->dir->dir->valor == "C");
    CHECK(Teste::fim(f)->dir->dir->dir->valor == "C");
    CHECK(Teste::fim(f)->dir->dir->dir->dir->valor == "B");    
    CHECK(Teste::fim(f)->esq->valor == "B");
    CHECK(Teste::fim(f)->esq->esq->valor == "C");
    CHECK(Teste::fim(f)->esq->esq->esq->valor == "C");
    CHECK(Teste::fim(f)->esq->esq->esq->esq->valor == "A"); 

    Fila x;
    x.Inserir("Q");
    x.Inserir("W");
    REQUIRE(x.tamanho()==2);
    CHECK(Teste::fim(x)->dir->valor == "Q");
    CHECK(Teste::fim(x)->dir->dir->valor == "W");
  }

  TEST_CASE("RemoverPrimeiro()") {
    Fila f;
    f.Inserir("A");
    f.Inserir("C");
    f.Inserir("C");
    f.Inserir("B");
    f.RemoverPrimeiro();
    f.RemoverPrimeiro();
    REQUIRE(Teste::tamanho(f) == 2);
    CHECK(Teste::fim(f)->dir->valor == "C");
    CHECK(Teste::fim(f)->dir->dir->valor == "B");
    CHECK(Teste::fim(f)->esq->valor == "B");
    CHECK(Teste::fim(f)->esq->esq->valor == "C");

    Fila x;
    x.Inserir("Q");
    x.Inserir("W");
    REQUIRE(x.tamanho()==2);
    CHECK(Teste::fim(x)->dir->valor == "Q");
    CHECK(Teste::fim(x)->dir->dir->valor == "W");
    x.RemoverPrimeiro();
    CHECK_FALSE(Teste::fim(x)->dir->valor == "Q");
    CHECK(Teste::fim(x)->dir->valor == "W");
  }

  TEST_CASE("Fila(const Fila&)") {
    Fila f;
    f.Inserir("A");
    f.Inserir("X");
    f.Inserir("B");
    f.Inserir("X");
    Fila a(f);
    REQUIRE(Teste::tamanho(a) == 4);
    CHECK(Teste::fim(a)->dir->valor == "A");
    CHECK(Teste::fim(a)->dir->dir->valor == "X");
    CHECK(Teste::fim(a)->dir->dir->dir->valor == "B");
    CHECK(Teste::fim(a)->dir->dir->dir->dir->valor == "X");    
    CHECK(Teste::fim(a)->esq->valor == "X");
    CHECK(Teste::fim(a)->esq->esq->valor == "B");
    CHECK(Teste::fim(a)->esq->esq->esq->valor == "X");
    CHECK(Teste::fim(a)->esq->esq->esq->esq->valor == "A"); 
  
    Fila x;
    x.Inserir("Q");
    x.Inserir("W");
    Fila y(x);
    CHECK(Teste::fim(y)->dir->valor == "Q");
    CHECK(Teste::fim(y)->dir->dir->valor == "W");
  }

  TEST_CASE("vazia()"){
    Fila f;
    CHECK(f.vazia() == true);
    f.Inserir("A");
    CHECK(f.vazia() == false);
    f.Inserir("A");
    f.RemoverPrimeiro();    
    CHECK(f.vazia() == false);   
    f.RemoverPrimeiro();     
    CHECK(f.vazia() == true);

    Fila x;
    CHECK(x.vazia() == true);
    x.Inserir("X");
    CHECK_FALSE(x.vazia() == true);
  }

  TEST_CASE("tamanho()"){
    Fila f;
    CHECK(f.tamanho() == 0);
    for (int i = 1; i <= 10; i++) {
      f.Inserir("");
      CHECK(f.tamanho() == i);
    }
    for (int i = 10; i >= 1; i--) {
      f.RemoverPrimeiro();
      CHECK(f.tamanho() == i - 1);
    }
    CHECK(f.tamanho() == 0);

    Fila x;
    x.Inserir("A");
    CHECK(x.tamanho()==1);
    x.Inserir("A");
    CHECK(x.tamanho()==2);
    x.Inserir("A");
    CHECK(x.tamanho()==3);
  }

  TEST_CASE("primeiro()"){
    Fila f;
    for (int i = 1; i <= 10; i++) {
      f.Inserir(std::to_string(i));
    }
    for (int i = 1; i <= 10; i++) {
      string s = f.primeiro();
      CHECK(s == std::to_string(i));
      f.RemoverPrimeiro();
    }

    Fila x;
    x.Inserir("A");
    CHECK(x.primeiro()=="A");
    x.Inserir("B");
    CHECK(x.primeiro()=="A");
    x.RemoverPrimeiro();
    CHECK(x.primeiro()=="B");
    x.Inserir("A");
    CHECK(x.primeiro()=="B");
  }

  TEST_CASE("operator==(const Fila&)") {
    Fila a;
    a.Inserir("A");
    a.Inserir("C");
    a.Inserir("C");
    a.Inserir("C");
    a.Inserir("B");
    Fila b;
    b.Inserir("C");
    b.Inserir("B");
    b.Inserir("B");
    b.Inserir("B");
    b.Inserir("A");
    CHECK_FALSE(a == b);

    Fila a2;
    a2.Inserir("A");
    a2.Inserir("C");
    a2.Inserir("C");
    a2.Inserir("C");
    a2.Inserir("B");
    CHECK(a2 == a);

    Fila x;
    x.Inserir("Q");
    x.Inserir("B");
    Fila y;
    y.Inserir("Q");
    y.Inserir("B");
    CHECK(x==y);
  }

  TEST_CASE("operator=(const Fila&)") {
    Fila f;
    f.Inserir("A");
    f.Inserir("X");
    f.Inserir("B");
    f.Inserir("X");
    Fila a;
    a = f;
    REQUIRE(Teste::tamanho(a) == 4);
    CHECK(Teste::fim(a)->dir->valor == "A");
    CHECK(Teste::fim(a)->dir->dir->valor == "X");
    CHECK(Teste::fim(a)->dir->dir->dir->valor == "B");
    CHECK(Teste::fim(a)->dir->dir->dir->dir->valor == "X");    
    CHECK(Teste::fim(a)->esq->valor == "X");
    CHECK(Teste::fim(a)->esq->esq->valor == "B");
    CHECK(Teste::fim(a)->esq->esq->esq->valor == "X");
    CHECK(Teste::fim(a)->esq->esq->esq->esq->valor == "A"); 

    Fila x;
    x.Inserir("Q");
    x.Inserir("B");
    Fila y;
    y=x;
    CHECK(x==y);
  }
  
} 