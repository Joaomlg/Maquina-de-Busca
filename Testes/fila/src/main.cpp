#include <iostream>
#include <string>

#include "fila.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;

std::ostream& operator<< (std::ostream& out, const Fila& c) {
  Fila x(c);
  out << "[";
  while(x.tamanho() > 1){
    string e = x.primeiro();
    out << e << ", ";
    x.RemoverPrimeiro();
  }
  out << x.primeiro() << "]";
  return out;
}

int main() {
  // x = [0, 2, 4, 6, 8].
  Fila x;
  for (int i = 0; i < 10; i += 2) {
    x.Inserir(to_string(i));
  }
  cout << "x = " << x << endl;
  // x2 == x.
  Fila x2(x); 
  cout << "x2 = " << x << endl;
  // x3 == x.
  Fila x3;
  x3 = x;
  cout << "x3 = " << x << endl; 
  // y = [a0, a2, a4, a6, a8].
  Fila y;
  for (int i = 0; i < 10; i += 2) {
    y.Inserir("a" + to_string(i));
  }
  cout << "y = " << y << endl; 
  // Testa se x2 == x3.
  if (x2 == x3) {
    cout << "x2 == x3" << endl;
  } else {
    cout << "x2 != x3" << endl;
  }
  // Testa se x != y.
  if (x == y) {
    cout << "x == y" << endl;
  } else {
    cout << "x != y" << endl;
  }
}