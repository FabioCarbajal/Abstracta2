#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

class Affin{
private:
	string alfa="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-0123456789";
	int clave_a;
	int clave_b;
	int clave_privada;
	
public:
	Affin(){
		srand(time(NULL));
		clave_a=rand();
		while(euclides(clave_a,alfa.length()) != 1){
			clave_a=rand();
		}
		clave_b=rand()%alfa.length();
		clave_privada=inversa(clave_a,alfa.length());
		cout<<"Clave Publica:"<<clave_a<<endl;
		//cout<<"Clave Privada:"<<clave_privada<<endl;
		cout<<"Segunda Clave:"<<clave_b<<endl;
	}
	Affin(int a, int b){
		this -> clave_a=a;
		this -> clave_b=b;
		clave_privada=inversa(clave_a,alfa.length());
	}
	
	string cifrar(string mensaje){
		for(int i=0;i <= mensaje.length();i++){
			int aux=modulo(clave_a,alfa.length());
			aux=aux*alfa.find(mensaje[i]);
			aux=modulo(aux,alfa.length())+modulo(clave_b,alfa.length());
			aux=modulo(aux,alfa.length());
			mensaje[i]=alfa[aux];
		}
		return mensaje;
	}
	
	string descifrar(string mensaje){
		for(int i = 0; i <= mensaje.length(); i++){
			int aux = modulo(clave_b,alfa.length());
			aux = alfa.find(mensaje[i]) - aux;
			aux = modulo(clave_privada,alfa.length()) * aux;
			aux = modulo(aux,alfa.length());
			mensaje[i] = alfa[aux];
		}
		return mensaje;
	}
	int modulo(int a, int n); 
	int euclides(int a, int b);
	int inversa(int a, int b);
};

int Affin::modulo(int a, int n){
	int q=a/n;
	int r=a-q*n;
	if(r<0){
		r+=n;
	}
	return r;
}
	
int Affin::euclides(int a, int b){
	int r=modulo(a,b);
	while(r!=0){
		a=b;
		b=r;
		r=modulo(a,b);
	}
	return b;
}
int Affin::inversa(int a, int b){
	int r1=a;
	int r2=b;
	int q,r,s;
	int s1=1;
	int s2=0;
	
	while(r2>0){
		q=r1/r2;
		r=r1-q*r2;
		r1=r2;
		r2=r;
		
		s=s1-q*s2;
		s1=s2;
		s2=s;
	}
	if(s1<0){
		return modulo(s1,b);
	}
	return s1;
}

int main(){
	string mensaje="iD.nt.jtjW.lD2lW8UWj2.iD.2lWQrlWjW.DU.UDj.SDUYW.1l2jW.a4j. hOj.6ljW.a4j.WDhSj.74j.WrD.lD.nt.2lWQFhOj.vUl6lDQ.4jha.WrnnjF.WajDO4.Ajha4.a4j.y6hOS.a4j.WSt.6UUSW.2jh2.Lh66.nt.Dhnj.a4FUrQ4.a4j.OFjhn.eD2.i66.4jhF.tUr.WOFjhn.hQhlD.5haFlOS.9hHljF.khFprjJ.L4Uprj.ZfZsZIsuwdKu";
	Affin a1(17,7);
	mensaje=a1.descifrar(mensaje);
	cout<<"Mensaje Descifrado: "<<mensaje<<endl;
	return 0;
}

