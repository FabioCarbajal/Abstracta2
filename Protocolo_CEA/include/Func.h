#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

const string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int modulo(int,int);
int euclides(int, int);
vector<int> euclides_extendido(int,int);
int inversa(int,int);
int generar_Aleatorio();
int generar_Aleatorio_Max(int);
void generar_claves_affin(int&,int&,int);

#endif // FUNC_H
