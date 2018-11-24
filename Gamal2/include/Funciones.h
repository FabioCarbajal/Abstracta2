#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>
#include <sstream>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ a, ZZ n);
ZZ euclides(ZZ a, ZZ b);
ZZ mcd(ZZ a, ZZ b);
vector <ZZ> euclides_extendido(ZZ a, ZZ b);
ZZ inversa(ZZ a, ZZ alfabeto);
ZZ potencia(ZZ a, ZZ b, ZZ modu);
string zzToString(ZZ z);
ZZ stringTozz(string str);
vector<bool> ZZtoBinary(ZZ num);
ZZ potenciaMod(ZZ n, ZZ m, ZZ mod);

ZZ raiz_primitiva(ZZ p);

#endif
