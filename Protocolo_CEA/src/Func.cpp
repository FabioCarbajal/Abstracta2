#include "../include/Func.h"

int modulo(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}

int euclides(int a, int b)
{
    int res=modulo(a,b);
    while(res!=0)
    {
        ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
        a=b;
        b=res;
        res=modulo(a,b);
    }
    ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
    return b;
}

vector<int> euclides_extendido(int a,int b)
{
    vector<int> result;
    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    int q , r , x , y;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 - q*x2;
        x1 = x2;
        x2 = x;
    }
    result.push_back(x1);
    result.push_back(x2);
    result.push_back(euclides(a,b));
    return result;
}
int inversa(int a, int b)
{
    vector<int> temp;
    temp = euclides_extendido(a,b);
    if(temp[0]<0){
        return temp[0]+b;
    }
    else{
        return temp[0];
    }
}
int generar_Aleatorio(){

    int numero_aleatorio=rand();  ///Numeros entre 1-1000
    return numero_aleatorio;
}
int generar_Aleatorio_Max(int max){

    int numero_aleatorio=rand()%(max);  ///Numeros entre 1-1000
    return numero_aleatorio;
}
int generar_Aleatorio_Max_b(int max){

    int numero_aleatorio=10+rand()%(max);  ///Numeros entre 1-1000
    return numero_aleatorio;
}
void generar_claves_affin(int &a,int &b, int mod)
{
    a = generar_Aleatorio_Max_b(mod);
    while(euclides(a,mod)!=1){
        a=generar_Aleatorio_Max_b(mod);
    }
    b=generar_Aleatorio_Max_b(mod);
}
