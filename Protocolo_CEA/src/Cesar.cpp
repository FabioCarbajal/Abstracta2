#include "../include/Cesar.h"

Cesar::Cesar(int clave1)
{
    clave = clave1;
    cout <<"La clave es :"<<clave<<endl;
}
string Cesar::Encriptado(string mensaje_original)
{
    string mensaje_encriptado;
    for(int i = 0; i<mensaje_original.size(); i++){
        int cuack = alfabeto.find(mensaje_original[i]);
        cuack =modulo(cuack+clave,alfabeto.length());
        mensaje_encriptado += alfabeto[cuack];
    }
    return mensaje_encriptado;
}
string Cesar::Desencriptado(string mensaje_encriptado)
{
    string mensaje_desencriptado;
    for(int i = 0; i<mensaje_encriptado.size(); i++){
        int cuack2 = alfabeto.find(mensaje_encriptado[i]);
        cuack2=modulo(cuack2-clave,alfabeto.length());
        mensaje_desencriptado += alfabeto[cuack2];
    }
    return mensaje_desencriptado;
}
