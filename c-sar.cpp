#include <iostream>
#include <string>
using namespace std;

class Cesar
{
	int clave;
public:
	Cesar(int clavecita){
		clave=clavecita;
		cout<<"la clave es: "<<clave;
	}
		
	string alfabeto="abcdefghijklmnopqrstuvwxyz";
	
	string cifrar(string mensaje){
		for(int i=0;i<mensaje.length();i++){
			int posicion=alfabeto.find(mensaje[i]);
			int n=posicion+clave;
			mensaje += alfabeto[posicion];
		}
		
		return mensaje;
	}
	
	string descifrar(string mensaje){
		for(int j=0;j<mensaje.length();j++){
			int descifrapos=alfabeto.find(mensaje[j])-clave;
			int n=descifrapos-clave;
		}
		return mensaje;
	}
};



int main(int argc, char *argv[]) {
	string mensaje="ella no te ama";
	int clave=3;
	Cesar prueba(clave);
	string cif=prueba.cifrar(mensaje);
	cout<<cif;
	return 0;
}

