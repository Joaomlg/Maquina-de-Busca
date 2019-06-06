// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos - Coordenadas Euclidianas.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../complexo/complexo.h"
#include "../include/doctest.h"

#include <limits>

class Teste
{
public:
  static double real(const Complexo &c)
  {
    return c.real_;
  }
  static double imag(const Complexo &c)
  {
    return c.imag_;
  }
};

std::ostream& operator<< (std::ostream& os, const Complexo& c) {
  if (c.imag() >= 0.0) {
    os << c.real() << " + " << c.imag() << "i";
  } else {
    os << c.real() << " - " << -c.imag() << "i";
  }
  return os;
}

TEST_SUITE("Complexo") {
  TEST_CASE("Complexo::Complexo()") {
    Complexo zero;
    CHECK(Teste::real(zero) == 0.0);
    CHECK(Teste::imag(zero) == 0.0);
    
    Complexo nulo;
    CHECK(nulo.real()==0.0);
    CHECK(nulo.imag()==0.0);
  }

  TEST_CASE("Complexo::Complexo(double)") {
    Complexo a(2);
    CHECK(Teste::real(a) == 2.0);
    CHECK(Teste::imag(a) == 0.0);

    Complexo onlyReal(8);
    CHECK(onlyReal.real()==8.0);
    REQUIRE(onlyReal.imag()==0.0);
    CHECK_FALSE(onlyReal.real()==9.0);
  }

  TEST_CASE("Complexo::Complexo(double, double)") {
    Complexo a(-2.0, -3.0);
    CHECK(Teste::real(a) == -2.0);
    CHECK(Teste::imag(a) == -3.0);

    Complexo x(2,9);
    CHECK(x.real()==2.0);
    CHECK(x.imag()==9.0);
  }

  TEST_CASE("Complexo::real()") {
    Complexo a(2.0, 3.0);
    CHECK(a.real() == 2.0);

    Complexo b(-2.0, 3.0);
    CHECK(b.real() == -2.0);

    Complexo c(4.3);
    CHECK(c.real()==4.3);
  }

  TEST_CASE("Complexo::imag()") {
    Complexo a(2.0, 3.0);
    CHECK(a.imag() == 3.0);

    Complexo b(2.0, -3.0);
    CHECK(b.imag() == -3.0);

    Complexo c(3.0, 7.0);
    CHECK(c.imag()==7.0);
  }

  TEST_CASE("Complexo::operator==(Complexo)"){
    Complexo zero;
    Complexo comparar;
    Complexo a(2, 3);
    Complexo b(2, -3);
    CHECK(zero == comparar);
    CHECK(a == a);
    CHECK_FALSE(b == a);

    Complexo c(9, 8);
    Complexo nulo;
    CHECK_FALSE(c==nulo);
    CHECK(c == Complexo(9,8));
    
  }

  TEST_CASE("Complexo::operator=(Complexo)"){
    Complexo a(2, 3);
    Complexo b(4, 5);
    CHECK_FALSE(b == Complexo(2, 3));
    b = a;
    CHECK(b == Complexo(2, 3));

    Complexo c;
    c = Complexo(4,5);
    CHECK(c==Complexo(4,5));
  }

  TEST_CASE("Complexo::modulo()") {
    Complexo a(3.0, 4.0);
    CHECK(a.modulo() == 5.0);
  
    Complexo b(1.0, 1.0);
    CHECK(b.modulo() - 1.414213 <= 1E-6);

    Complexo c(8,6);
    CHECK(c.modulo()==10);
  }

  TEST_CASE("Complexo::conjugado()") {
    Complexo zero;
    Complexo a(2, 3);
    Complexo b(2, -3);
    CHECK((zero.conjugado() == Complexo(0, 0)));
    CHECK((a.conjugado().conjugado() == a));
    CHECK((a.conjugado() == Complexo(2.0, -3.0)));
    CHECK((b.conjugado() == Complexo(2.0, 3.0)));

    Complexo c(9,-8);
    CHECK(Complexo(9,8)==c.conjugado());
  }

  TEST_CASE("Complexo::operador-()") {
    Complexo zero;
    CHECK(-zero == Complexo(0, 0));

    Complexo a(2, 0);
    CHECK(-a == Complexo(-2, 0));

    Complexo b(-2, 0);
    CHECK(-b == Complexo(2, 0));

    Complexo c(0, 2);
    CHECK(-c == Complexo(0, -2));

    Complexo d(4, 2);
    CHECK((-d == Complexo(-4, -2)));

    Complexo e(-5,9);
    CHECK(-e==Complexo(5,-9));
  }

  TEST_CASE("Complexo::inverso()") {
    Complexo a(0, 2);
    CHECK(a.inverso() ==  Complexo(0, -1.0 / 2));

    Complexo b(2.0, 0.0);
    CHECK(b.inverso() == Complexo(1.0 / 2, 0));

    Complexo c(4.0, 2.0);
    CHECK(c.inverso() == Complexo(4.0/20.0,-2.0/20.0));
  }

  TEST_CASE("Complexo::operator+(Complexo)") {
    Complexo zero;
    Complexo a(2, 3);
    Complexo b(-2, -3);
    CHECK(zero + zero == Complexo(0, 0));
    CHECK(zero + a ==  Complexo(2, 3));
    CHECK(b + zero ==  Complexo(-2, -3));
    CHECK(a + b == Complexo(0, 0));

    CHECK(Complexo(3,2)+Complexo(1,4)==Complexo(4,6));
  }

  TEST_CASE("Complexo::operator-(Complexo)") {
    Complexo zero;
    Complexo a(2, 3);
    Complexo b(-2, -3);
    CHECK(zero - zero == Complexo(0, 0));
    CHECK(zero - a ==  Complexo(-2, -3));
    CHECK(b - zero ==  Complexo(-2, -3));
    CHECK(a - b == Complexo(4, 6));
    CHECK(b - a == Complexo(-4, -6));

    CHECK(Complexo(3,2)-Complexo(1,4)==Complexo(2,-2));
  }

  TEST_CASE("Complexo::operator*(Complexo)") {
    Complexo zero;
    Complexo b(2, 3);
    Complexo c(-2, -3);
    Complexo d(0, 1);
    CHECK(zero * zero == Complexo(0, 0));
    CHECK(zero * b ==  Complexo(0, 0));
    CHECK(c * zero ==  Complexo(0, 0));
    CHECK(b * c == Complexo(5, -12));
    CHECK(b * c == c * b);
    CHECK(d * d == Complexo(-1, 0));

    CHECK(Complexo(3,2)*Complexo(1,4)==Complexo(3*1-2*4,3*4+2*1));
  }

  TEST_CASE("Complexo::operator/(Complexo)") {
    Complexo zero;
    Complexo a(2, 3);
    Complexo b(-2, -3);
    Complexo c(0, 1);
    CHECK(a / a ==  Complexo(1, 0));
    CHECK(zero / a ==  Complexo(0, 0));
    CHECK(a / b == Complexo(-1, 0));
    CHECK(b / a == Complexo(-1, 0));
    CHECK(c / c == Complexo(1, 0));
    
    Complexo d(0,1);
    Complexo e(1,0);
    CHECK( d / e == Complexo(0,1));
  }
}
