#ifndef RSA_H
#define RSA_H
#include "Funciones.h"
#include <string>
#include <iostream>
#include <NTL/ZZ.h>

using namespace std;

class RSA
{
private:
    string alfabeto = "abcdefghijklmnñopqrstuvwxyz.-_ABCDEFGHIJKLMNÑOPQRSTUVWXYZ0123456789";
    ZZ p;
    ZZ q;
    ZZ N;
    ZZ pub;
    ZZ priv;
public:
    RSA();
    RSA(ZZ a,ZZ b);
    void imprimir_claves();
    vector<ZZ> cifrar(string mensaje);
    string descifrar(vector<ZZ> mensaje);
};

#endif // RSA_H
