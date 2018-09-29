#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <vector>
#include <NTL/ZZ.h>

using namespace std;

ZZ modulo(ZZ a, ZZ b);
ZZ euclides(ZZ a, ZZ b);
vector <ZZ> euclides_extendido(ZZ a, ZZ b);
ZZ inversa(ZZ a, ZZ b);
bool primo(ZZ a);
ZZ potencia_i(ZZ a, ZZ b, ZZ modu);

#endif
