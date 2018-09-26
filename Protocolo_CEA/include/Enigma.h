#ifndef ENIGMA_H
#define ENIGMA_H
#include "Func.h"

class Enigma
{

    public:
        Enigma(string,int,int,int);
        Enigma(string,int,int,int,string,string);
        string Encriptado(string);
        string Desencriptado(string);
        string elegir_rotores(int);

        ///string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string rotor_i="EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        string rotor_i2="AJDKSIRUXBLHWTMCQGZNPYFVOE";
        string rotor_i3="BDFHJLCPRTXVZNYEIWGAKMUSQO";
        string rotor_i4="ESOVPZJAYQUIRHXLNFTGKDCMWB";
        string rotor_i5="VZBRGITYUPSDNHLXAWMJQOFECK";
        string rotor_i6="JPGVOUMFYQBENHZRDKASXLICTW";
        string rotor_i7="NZJHGRCXMYSWBOUFAIVLPEKQDT";
        string rotor_i8="FKQHTLXOCBJSPDZRAMEWNIUYGV";
        string reflector="YRUHQSLDPXNGOKMIEBFZCWVJAT";

        string Cifrado(string);
        string Descifrado(string);
    private:
        string sk;
        string clave;
        string r1;
        string r2;
        string r3;
        string l1;
        string l2;
        string l3;
        string limite="RFWKAANA";
        int temp;

};

#endif // ENIGMA_H
