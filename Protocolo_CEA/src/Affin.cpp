#include "../include/Affin.h"

Affin::Affin()
{
    tam = alfabeto.length();
    generar_claves_affin(clave_a,clave_b,tam);
    inversa_a=inversa(clave_a, tam);
    /*cout <<"ALFABETO LEN :"<<alfabeto.length()<<endl;
    cout <<"Clave A: "<<clave_a<<endl;
    cout <<"Clave B: "<<clave_b<<endl;
    cout <<"Inversa A :"<<inversa_a<<endl;*/
}
Affin::Affin(int c1, int c2)
{
    tam = alfabeto.length();
    clave_a = c1;
    clave_b = c2;
    inversa_a=inversa(clave_a, tam);
    /*cout <<"ALFABETO LEN :"<<alfabeto.length()<<endl;
    cout <<"Clave A: "<<clave_a<<endl;
    cout <<"Clave B: "<<clave_b<<endl;
    cout <<"Inversa A :"<<inversa_a<<endl;*/
}

string Affin::Affin_Encriptacion(string mensaje)
{
    string mensaje_cifrado;
    int pos;
    for(unsigned int i=0;i<mensaje.length();i++){
        pos = alfabeto.find(mensaje[i]);
        pos = modulo(pos*clave_a,tam);
        pos = modulo(pos+clave_b,tam);
        mensaje_cifrado+=alfabeto[pos];
    }
    return mensaje_cifrado;
}
string Affin::Affin_Desencriptacion(string mensaje_Encriptado)
{
    string mensaje_Descifrado;
    int pos;
    for(unsigned int i=0;i<mensaje_Encriptado.length();i++){
        pos = alfabeto.find(mensaje_Encriptado[i]);
        pos = modulo(pos-clave_b,tam);
        pos = modulo(pos*inversa_a,tam);
        mensaje_Descifrado+=alfabeto[pos];
    }
    return mensaje_Descifrado;
}
int Affin::get_clave_a()
{
    return clave_a;
}
int Affin::get_clave_b()
{
    return clave_b;
}
