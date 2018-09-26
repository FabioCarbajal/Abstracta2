#include "Protocolo.h"

Protocolo::Protocolo()
{
    tam = alfabeto.length();
    ///cout <<"TE ESTOY BUSCANDO PARA EXPLOTAR CONTIGO"<<endl;
}
Protocolo::Protocolo(string cod_alumno1,string nombr_iniciales,string apell_iniciales,string steckers_apell)
{
    tam = alfabeto.length();
    e1=cod_alumno1;
    e2=nombr_iniciales;
    e3=apell_iniciales;
    e4=steckers_apell;
    alea_cesar = 10+generar_Aleatorio_Max(tam);
}
string Protocolo::leer_txt()
{
    string mensaje;
    Fichero_Entrada.open("Fichero_Salida.txt");
    getline(Fichero_Entrada,mensaje);
    cout <<mensaje<<endl;
    Fichero_Entrada.close();
    return mensaje;
}
void Protocolo::escribir_txt(string mensaje_a_ingresar)
{
    Fichero_Salida.open("Fichero_Salida.txt");
    Fichero_Salida << mensaje_a_ingresar;
    Fichero_Salida.close();
    cout <<"c mamo"<<endl;
}
string Protocolo::Encriptado(string mensaje_original)
{
    ///string e1 = "123";
    string mensaje_encriptado;
    string temp;
    ///string enigma_temp1,enigma_temp2,enigma_temp3;
    string enigma_temp1,affin_temp1;
    int clave_affin_a;
    int clave_affin_b;
    stringstream i1(e1.substr(0,1));
    stringstream i2(e1.substr(1,1));
    stringstream i3(e1.substr(2,1));
    int a = 0;
    int b = 0;
    int c = 0;
    i1>>a;
    i2>>b;
    i3>>c;

    temp+=e2;
    temp+=e3;
    temp+=e4;
    temp+=mensaje_original;
    cout<<"PRUEBA: "<<mensaje_original<<endl;
    ///Cesar
    Cesar cesar(alea_cesar);
    temp=cesar.Encriptado(temp);


    ///Enigma enigma(temp.substr(0,3),a,b,c,temp.substr(3,3),temp.substr(6,2));
    Enigma enigma(e2,a,b,c,e3,e4);
    enigma_temp1 = temp.substr(8,500);
    enigma_temp1=enigma.Cifrado(enigma_temp1);
    Affin affin;
    clave_affin_a = affin.get_clave_a();
    clave_affin_b = affin.get_clave_b();
    affin_temp1 = affin.Affin_Encriptacion(enigma_temp1);

    stringstream a1,a2,c1;
    a1 << clave_affin_a;
    a2 << clave_affin_b;
    c1 << alea_cesar;
    cout<<"AFFA1: "<<clave_affin_a<<endl;
    cout<<"AFFA2: "<<clave_affin_b<<endl;

    mensaje_encriptado+=a1.str();
    mensaje_encriptado+=a2.str();
    mensaje_encriptado+='\n';
    mensaje_encriptado+=e1;
    mensaje_encriptado+=e2;
    mensaje_encriptado+=e3;
    mensaje_encriptado+=e4;
    mensaje_encriptado+='\n';
    mensaje_encriptado+=c1.str();
    mensaje_encriptado+='\n';
    mensaje_encriptado+=affin_temp1;

    escribir_txt(mensaje_encriptado);

    return mensaje_encriptado;
}
string Protocolo::Desencriptado()
{
    string mensaje_Desencriptado;
    string exit,s;
    ifstream infile;
	infile.open ("Fichero_Salida.txt");
    while(!infile.eof())
    {
        getline(infile,s);
        exit+=s;
    }
    cout <<exit<<endl;
	infile.close();
	string affin;
	affin = exit.substr(0,4);
	cout <<"AFFIN: "<<affin<<endl;
	string enigma;
	enigma = exit.substr(4,11);
	cout <<"ENIGMA: "<<enigma<<endl;
	string cesar;
	cesar = exit.substr(15,2);
	cout <<"CESAR: "<<cesar<<endl;
	string mensaje;
	mensaje = exit.substr(17,500);
	cout <<mensaje<<endl;
	stringstream a1(affin.substr(0,2));
	stringstream a2(affin.substr(2,2));
    int clave_affin_a = 0;
    int clave_affin_b = 0;
    a1>>clave_affin_a;
    a2>>clave_affin_b;
    cout <<"Affin A:"<<clave_affin_a<<endl;
    cout <<"Affin B:"<<clave_affin_b<<endl;
	Affin Pato1(clave_affin_a,clave_affin_b);
	string tmp1 = Pato1.Affin_Desencriptacion(mensaje);
	cout<<"TMP1: "<<tmp1<<endl;

	stringstream b1(enigma.substr(0,1));
	stringstream b2(enigma.substr(1,1));
	stringstream b3(enigma.substr(2,1));
	int rotores1 = 0;
	int rotores2 = 0;
	int rotores3 = 0;
	b1>>rotores1;
	b2>>rotores2;
	b3>>rotores3;
	Enigma Pato2(enigma.substr(3,3),rotores1,rotores2,rotores3,enigma.substr(6,3),enigma.substr(9,2));
	string tmp2 = Pato2.Descifrado(tmp1);
    cout<<"TMP2: "<<tmp2<<endl;
	stringstream c1(cesar.substr(0,2));
	int clave_cesar_a = 0;
	c1>>clave_cesar_a;
	Cesar Pato3(clave_cesar_a);
	string tmp3 = Pato3.Desencriptado(tmp2);
	cout<<"TMP3: "<<tmp3<<endl;

	mensaje_Desencriptado+=tmp3;

    return mensaje_Desencriptado;
}
