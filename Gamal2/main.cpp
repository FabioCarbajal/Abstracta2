#include <iostream>
#include <fstream>
#include "Gamal.h"

using namespace std;

int main()
{
    srand(time(NULL));
    string a, b, c;
    cout << "e1: ";
    cin >> a;
    cout << "e2: ";
    cin >> b;
    cout << "p: ";
    cin >> c;
    Gamal Prueba(stringTozz(a), stringTozz(b), stringTozz(c));
    string mensaje="hola";
    cout<<Prueba.cifrar(mensaje)<<endl;
    return 0;
}
