#include <iostream>
#include <string>
using namespace std;

class Cesar
{
	string alfabeto="abcdefghijklmnopqrstuvwxyz";
	int clave;
public:
	Cesar(int clavecita){
		clave=clavecita;
		cout<<"la clave es: "<<clave;
	}
	
	string cifrar(string mensaje){
		string mensenc;
		for(int i=0;i<mensaje.size();i++){
			int posicion=alfabeto.find(mensaje[i]);
			posicion+=clave;
			if(posicion>=alfabeto.size()){
				posicion-=clave;
			}
			mensenc+= alfabeto[posicion];
		}
		return mensenc;
	}
	
	string descifrar(string mensaje){
		string mensdes;
		for(int j=0;j<mensaje.length();j++){
			int posicion2=alfabeto.find(mensaje[j])-clave;
			if(posicion2<0){
				posicion2+=clave;
			}
			mensdes+=alfabeto[posicion2];
		}
			
		return mensdes;
	}
};



int main(int argc, char *argv[]) {
	string mensaje="hola";
	int clave=3;
	Cesar prueba(clave);
	string cif=prueba.cifrar(mensaje);
	cout<<cif<<endl;
	return 0;
}
