#ifndef PROTOCOLO_H
#define PROTOCOLO_H
#include "Cesar.h"
#include "Enigma.h"
#include "Affin.h"

class Protocolo
{
    public:
        Protocolo();
        Protocolo(string,string,string,string);
        ifstream Fichero_Entrada;
        ofstream Fichero_Salida;
        ///string mensaje_original;

        string leer_txt();
        void escribir_txt(string);
        string Encriptado(string);
        string Desencriptado();

        int tam;
        string e1;
        string e2;
        string e3;
        string e4;
        int alea_cesar;
        int aff1;
        int aff2;


    private:
};

#endif // PROTOCOLO_H
