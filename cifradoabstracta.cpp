#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char* cifrar(char*, char*);
char* cifrar(char* frase, char* alfabeto)
{
	int pos = 0;
	int longitud = 0;
	longitud = strlen(frase);
	
	while(true)
	{	
		for (int i = 0; i<26 ; i++)
		{
			if (frase[pos] == alfabeto[i])
			{
				frase[pos] = alfabeto[26-i-1];
				break;
			}
		}

		if (longitud == pos)
		{
			break;
		}
		pos++;
	}
	return(frase);
}

int main()
{
	char alfabeto[] = {"abcdefghijklmnopqrstuvwxyz"};
	char frase[256];
	
	cout<<"Ingrese texto: ";
	gets(frase);
	cout<<endl;
	
	int longitud  = 0;
	longitud = strlen(frase);
	char *frasecifrada = new char[longitud];
	
	frasecifrada = cifrar(frase,alfabeto);

	cout<<"Cifrado: ";
	for (int i = 0; i < longitud ; i++)
	{
		cout<<frasecifrada[i];
	}
	delete []frasecifrada;
	return 0;
}
