#include <vector>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;
using namespace NTL;

class RSA
{
private:
	ZZ d;
	ZZ N;
	ZZ p;
	ZZ q;
	string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-0123456789";
public:
    ZZ e;
	RSA();
	RSA(ZZ,ZZ);
	string cifrar(string);
	string descifrar(string);
    string zzToString(ZZ z);
	ZZ stringTozz(string str);
    vector<bool> ZZtoBinary(ZZ num);
    bool primo(ZZ a);
	void imprimir_claves();
	//funiones de operacion
	ZZ modulo(ZZ a, ZZ n);
	ZZ euclides(ZZ a, ZZ b);
	ZZ chino_RSA(ZZ);
	ZZ mcd(ZZ a, ZZ b);
	vector <ZZ> extendido(ZZ a, ZZ b);
	ZZ inversa(ZZ a, ZZ alfabeto);
	ZZ potencia(ZZ a, ZZ b, ZZ modu);
	ZZ potenciaMod(ZZ n, ZZ m, ZZ mod);
};

bool RSA::primo(ZZ a){
    if(euclides((ZZ)2,a)!=1) return 0;
    for(int i = 3; i < a; i+=2){
        if(euclides((ZZ)i,a)!=1) return 0;
    }
    return 1;
}

RSA::RSA()
{
    int aleatorio=RandomBnd(1000);
    ZZ p = to_ZZ(aleatorio);
    while(!primo(p)){
        ZZ p = to_ZZ(aleatorio);
    }
    ZZ q = to_ZZ(aleatorio);
    while(!primo(q)){
        ZZ q = to_ZZ(aleatorio);
    }
    ZZ N = p * q;
    ZZ e = to_ZZ(aleatorio);
    ZZ phi = (p-1)*(q-1);
    while(euclides(e,phi) != 1 && phi < e){
            e = to_ZZ(aleatorio);
    }
    ZZ d = inversa(e,phi);

}

RSA::RSA(ZZ publica, ZZ n){
    this -> e = publica;
    this -> N = n;
    //COLOCAR VALORES DIRECTOS DE P Y Q(en el concstrucotr por defecto )
}

void RSA::imprimir_claves(){
    cout << "Clave publica: " << this -> e << endl;
    cout << "N: " << this -> N << endl;
}

ZZ RSA::chino_RSA(ZZ num){
    ZZ d1 = modulo(d,p-1);
    ZZ d2 = modulo(d,q-1);
    ZZ D1 = modulo(num,p);
    D1 = potencia(D1,d1,p);
    ZZ D2 = modulo(num,q);
    D2 = potencia(D2,d2,q);
    ZZ P = p*q;
    ZZ P1 = P/p;
    ZZ P2 = P/q;
    ZZ Q1 = inversa(P1,p);
    ZZ Q2 = inversa(P2,q);
    ZZ rpta = modulo(D1 * P1 * Q1,P);
    rpta += modulo(D2 * P2 * Q2,P);
    rpta = modulo(rpta,P);
    return rpta;
}

string RSA::cifrar(string mensaje){
    string digitos;

    for(int i = 0; i < mensaje.size(); i++){
        ZZ pos = to_ZZ(alfabeto.find(mensaje[i]));
        string nume = zzToString(to_ZZ(alfabeto.find(alfabeto[alfabeto.size()-1])));
        int posicion = zzToString(pos).size();
        if(posicion < nume.size()){ //relleno con ceros
            digitos += "0";
            posicion++;
        }
        digitos += zzToString(pos);
    }
    ZZ temp = to_ZZ(digitos.size());
    ZZ N_1 = to_ZZ(zzToString(N).size()-1);
    while(modulo(temp,N_1) != 0){//quitar para funcion aparte
        int pos = alfabeto.find("w");
        digitos += zzToString(to_ZZ(pos));
        temp = to_ZZ(digitos.size());
    }
    string digito2;
    for(int j = 0; j < digitos.size();){
        int temp = 0;
        string tempi;
        while(temp < to_int(N_1)){
            tempi += digitos[j];
            ++temp;
            p;
            ++j;
        }
        ZZ temp_2 = potenciaMod(stringTozz(tempi),e,N);
        ZZ cont_num = to_ZZ(zzToString(temp_2).size());
        while(cont_num < zzToString(N).size()){//quitar para funcion
            digito2 += "0";
            ++cont_num;
        }
        digito2 += zzToString(temp_2);
    }
    return digito2;
}

string RSA::descifrar(string mensaje){
    string resultado;
    int num = (zzToString(N).size());
    for(int i = 0; i < mensaje.size();){
        int a = 0;
        string temp;
        while(a < num){
            a++;
            temp += mensaje[i];
            ++i;
        }
        ZZ valor = chino_RSA(stringTozz(temp));
        int x = zzToString(valor).size();
        while(x < zzToString(N).size()-1){
            resultado += "0";
            ++x;
        }
        resultado += zzToString(valor);
    }
    string dig = zzToString(to_ZZ(alfabeto.size()-1));
    string rpta;
    for(int j = 0; j < resultado.size();){
        int s = 0;
        string tempi;
        while(s < dig.size()){
            tempi += resultado[j];
            ++s;
            ++j;
        }
        rpta += alfabeto[to_int(stringTozz(tempi))];
    }
    while(rpta[rpta.size()-1] == 'w'){
        rpta.erase(rpta.size()-1);
    }
    return rpta;
}

ZZ RSA::modulo(ZZ a, ZZ n)
{
    ZZ q, r;
	q = a / n;
	r = a - (q*n);
	if (r < 0)
		r += n;
	return r;
}

ZZ RSA::euclides(ZZ a, ZZ b)
{
     ZZ residuo = modulo(a,b);
     while(residuo!=0)
     {
         a = b;
         b = residuo;
         residuo = modulo(a,b);
     }
     return b;
}

ZZ RSA::mcd(ZZ a, ZZ b)
{
    ZZ resultado;
    resultado = 1;
    ZZ i;
    for(i=1;i<=a;i++)
    {
        if((modulo(a,i)==0)&&(modulo(b,i)==0))
        {
            resultado = i;
        }
    }
    return resultado;
}

vector <ZZ> RSA::extendido(ZZ a, ZZ b)
{
    vector <ZZ> resultados;
    ZZ r1,s1,t1,r2,s2,t2,q,r;
    r1 = a;
    r2 = b;
    s1 = 1;
    s2 = 0;
    t1 = 0;
    t2 = 1;
    while(r2>0)
    {
        q = r1/r2;

        ZZ r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        ZZ s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        ZZ t = t1 - q * t2;
        t1 = t2;
        t2 = t;

    }
    resultados.push_back(r1);
    resultados.push_back(s1);
    resultados.push_back(t1);
    return resultados;
}

ZZ RSA::inversa(ZZ a, ZZ alfabeto)
{
    ZZ x = extendido(a,alfabeto)[1];
    if(x<0)
    {
        return modulo(x,alfabeto);
    }
    return x;
}

ZZ RSA::potencia(ZZ a, ZZ b, ZZ modu)
{
    ZZ result = to_ZZ(1);
    ZZ n = to_ZZ(2);
    ZZ x = to_ZZ(a);
    while(b != 0){
        if(modulo(b,n)==1){
            result = modulo((result * x),modu);
        }
        x = modulo((x * x),modu);
        b = b/2;
    }
    return result;
}

string RSA::zzToString(ZZ z) {
    std::stringstream buffer;
    buffer << z;
    return buffer.str();
}

ZZ RSA::stringTozz(string str){
    ZZ number(INIT_VAL, str.c_str());
    return number;
}

vector<bool> RSA::ZZtoBinary(ZZ num){
    vector<bool> binario;
    while(num>0){
        binario.push_back(to_int(modulo(num,to_ZZ(2))));
        num=num>>1;
    }
    return binario;
}

ZZ RSA::potenciaMod(ZZ n, ZZ m, ZZ mod){
    if(n>mod)
        n=modulo(n,mod);
    vector<bool> b=ZZtoBinary(m);
    ZZ d=to_ZZ(1);
	for(int i=b.size();i>0;i--){
        d=modulo(d*d,mod);
        if(b[i-1]==1)
            d=modulo(d*n,mod);
	}
	return d;
}

int main()
{
    ZZ a, b;
    cout << "Ingrese clave publica: ";
    cin >> a;
    cout << "Ingrese N: ";
    cin >> b;
    RSA Prueba;
    ifstream ficheroEntrada;
    string mensaje;
    ficheroEntrada.open("texto.txt");
    getline(ficheroEntrada,mensaje);
    ficheroEntrada.close();
    ofstream ficheroSalida;
    ficheroSalida.open("mensaje.txt");
    ficheroSalida << Prueba.cifrar(mensaje);
    ficheroSalida.close();
    return 0;
    }
