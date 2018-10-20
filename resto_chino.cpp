#include <iostream>
#include <vector>

using namespace std;

int modulo(int a, int n)
{
	int q, r;
	q = a / n;
	r = a - (q*n);
	if (r < 0)
		r += n;
	return r;
}

int euclides(int a, int b)
{
	int residuo = modulo(a,b);
	while(residuo!=0)
	{
		a = b;
		b = residuo;
		residuo = modulo(a,b);
	}
	return b;
}

vector <int> euclides_extendido(int a, int b)
{
	vector <int> resultados;
	int r1,s1,t1,r2,s2,t2,q,r;
	r1 = a;
	r2 = b;
	s1 = 1;
	s2 = 0;
	t1 = 0;
	t2 = 1;
	while(r2>0)
	{
		q = r1/r2;
		
		int r = r1 - q * r2;
		r1 = r2;
		r2 = r;
		
		int s = s1 - q * s2;
		s1 = s2;
		s2 = s;
		
		int t = t1 - q * t2;
		t1 = t2;
		t2 = t;
		
	}
	resultados.push_back(r1);
	resultados.push_back(s1);
	resultados.push_back(t1);
	return resultados;
}

int inversa(int a, int alfabeto)
{
	int x = euclides_extendido(a,alfabeto)[1];
	if(x<0)
	{
		return modulo(x,alfabeto);
	}
	return x;
}

int multipli(int a, int b, int c){
	return modulo(modulo(a,c) * modulo(b,c),c);
}

int mult_mod(int a, int b, int c){
	cout << "(" << a << " mod " << c << " * " << b << " mod " << c << ")" << " mod " << c << endl;
	cout << "(" << modulo(a,c) << " * " << modulo(b,c) << ")" << " mod " << c << endl;
	cout << modulo(a,c) * modulo(b,c) << " mod " << c << endl;
	cout << modulo(modulo(a,c) * modulo(b,c),c) << " mod " << c << endl;
	return modulo(modulo(a,c) * modulo(b,c),c);
}

int res_chino(vector<int> valores, vector<int> modulos){
	
	for(int i = 0; i < valores.size(); i++){
		for(int j = i+1; j < valores.size(); j++){
			if(euclides(modulos[i],modulos[j]) != 1){
				cout << "Modulos no coprimos" << endl;
				return -1;
			}
		}
	}
	cout << endl;
	int resultado = 0;
	int M = 1;
	vector<int> sub_mods;
	vector<int> invers;
	for(int i = 0; i < valores.size(); i++){
		cout << "X = " << valores[i] << " mod " << modulos[i] << endl;
		M = M * modulos[i];
	}
	cout << endl;
	cout << "M: " << M << endl;
	for(int i = 0; i < valores.size(); i++){
		sub_mods.push_back(M/modulos[i]);
		invers.push_back(inversa(M/modulos[i],modulos[i]));
	}
	cout << endl;
	for(int i = 0; i < valores.size(); i++){
		cout << "M_" << i+1 << " = " << sub_mods[i] << endl;
	}
	cout << endl;
	for(int i = 0; i < valores.size(); i++){
		cout << "Inversa M_" << i+1 << " = " << invers[i] << endl;
	}
	cout << endl;
	cout << "X = (";
	for(int i = 0; i < valores.size(); i++){
		cout << valores[i] << " * " << sub_mods[i] << " * " << invers[i];
		resultado = modulo(resultado + (modulo(multipli(multipli(valores[i],sub_mods[i],M),invers[i],M),M)),M);
		if(i != (valores.size()-1))
			cout << " + ";
	}
	cout << ") mod " << M << endl;
	cout << endl;
	return resultado;
}

int chino(vector<int> valores, vector<int> modulos){
	int resultado = 0;
	int M = 1;
	vector<int> sub_mods;
	vector<int> invers;
	for(int i = 0; i < valores.size(); i++){
		M = M * modulos[i];
	}
	for(int i = 0; i < valores.size(); i++){
		sub_mods.push_back(M/modulos[i]);
		invers.push_back(inversa(M/modulos[i],modulos[i]));
	}
	for(int i = 0; i < valores.size(); i++){
		resultado = modulo(resultado + (modulo(multipli(multipli(valores[i],sub_mods[i],M),invers[i],M),M)),M);
	}
	return resultado;
}

int main(){
	vector<int> val;
	vector<int> mods;
	int tam;
	int a;
	int mod;
	cout << "Cantidad de ecuaciones: ";
	cin >> tam;
	for(int i = 0; i < tam; i++){
		cout << "Ingrese la ecuacion " << i+1 << ":";
		cin >> a;
		cin >> mod;
		val.push_back(a);
		mods.push_back(mod);
	}
	cout << "Respuesta: " << res_chino(val,mods);
	return 0;
}
