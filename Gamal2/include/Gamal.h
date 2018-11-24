#ifndef GAMAL_H
#define GAMAL_H
#include <string>
#include "Funciones.h"
#include <fstream>

class Gamal
{
private:
    ZZ p;
    ZZ d;
    ZZ e_1;
    ZZ e_2;
    string alfabeto = "0123456789abcdefghijklmnopqrstuvwxyz.,ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
    Gamal(int bits);
    Gamal(ZZ e1, ZZ e2, ZZ publica);
    string cifrar(string mensaje);
    string descifrar(string mensaje);
    void generar_claves(int bits);
    void impr_claves();

};

#endif // GAMAL_H
