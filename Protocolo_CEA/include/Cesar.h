#ifndef CESAR_H
#define CESAR_H
#include "Func.h"

class Cesar
{
    public:
        Cesar(int);
        string Encriptado(string);
        string Desencriptado(string);

        ///string alfabeto = "abcdefghijklmnopqrstuvxyz";

    private:

        int clave; ///int clave = 3;
        ///Accel Art
};

#endif // CESAR_H
