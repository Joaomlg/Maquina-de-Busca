// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos - Coordenadas Euclidianas.
//
// QUESTÃO 1:
// Implemente em complexo.cc as funções descritas em complexo.h.
//
// QUESTÃO 2:
// Escreva um programa que simula uma calculadora de números complexos.
// Ele deve apresentar um menu com as operações de soma, subtração,
// multiplicação, divisão, módulo e conjugado. Após o usuário escolher uma das
// funções, o programa deve ler o valor dos parâmetros e em seguida exibir o
// resultado da função.
//
// QUESTÃO 3:
// Escreva uma função "void CalcularRaizes(float a, float b, float c,
// Complexo* r1, Complexo* r2)" que recebe os coeficientes
// de uma equação de segundo grau "a.x^2 + b.x + c = 0" e retorna por r1 e r2
// as raízes (possivelmente complexas) desta equação.
//
// QUESTÃO 4:
// Escreva um programa que lê do teclado os coeficientes reais de uma equação de
// segundo grau e imprime na tela as raízes (possivelmente complexas) desta
// equação.

#include <cmath>
#include <iostream>
#include <sstream>

#include "complexo.h"

using namespace std;

void Imprimir(Complexo z) {
  cout << z.real();
  if (z.imag() >= 0.0) {
    cout << " + " << z.imag() << "i";
  } else {
    cout << " - " << -z.imag() << "i";
  }
  cout << endl;
}

int LerOpcaoDoTeclado() {
  int op;
  cout << "1.  Somar\n";
  cout << "2.  Subtrair\n";
  cout << "3.  Multiplicar\n";
  cout << "4.  Dividir\n";
  cout << "5.  Modulo\n";
  cout << "6.  Conjugado\n";
  cout << "7.  Sair\n\n\n";
  cout << "Digite o numero da opcao desejada: ";
  cin >> op;
  while (!(op >= 1 && op <= 7)) {
    cout << "Opcao Invalida! Digite o numero da opcao desejada: ";
    cin >> op;
  }
  return op;
}

Complexo LerComplexoDoTeclado() {
  float real;
  float imag;
  cout << "Digite o valor da parte real do numero complexo: ";
  cin >> real;
  cout << "Digite o valor da parte imaginaria do numero complexo: ";
  cin >> imag;
  Complexo c(real, imag);
  return c;
}

void ExecutarOperacao(int op) {
  Complexo c1;
  Complexo c2;
  c1 = LerComplexoDoTeclado();
  switch (op) {
    case 1:
      c2 = LerComplexoDoTeclado();
      Imprimir(c1 + c2);
      break;
    case 2:
      c2 = LerComplexoDoTeclado();
      Imprimir(c1 - c2);
      break;
    case 3:
      c2 = LerComplexoDoTeclado();
      Imprimir(c1 * c2);
      break;
    case 4:
      c2 = LerComplexoDoTeclado();
      Imprimir(c1 / c2);
      break;
    case 5:
      cout << c1.modulo() << endl;
      break;
    case 6:
      Imprimir(c1.conjugado());
      break;
  }
}

int main() {
  int op = LerOpcaoDoTeclado();
  ExecutarOperacao(op);
  return 0;
}
