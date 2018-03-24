#include <iostream>
#include <string>
using namespace std;

void invertir()
{
	string alfa={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'}; 
	string alfa2;
	int i,j,k;
	
	for(i=0;i<26;i++)
	{
		cout << alfa[i];
	}
	cout << endl;
	
	for(j=25;j>=0;j--)
	{
		cout << alfa[j];
	}
	cout << endl;
	
	char men[100];
	cout << "Introducir mensaje: ";
	cin.getline(men, 100, '\n');
	cout << "mensaje sin descifrar: " << men;
	
}

int main() 
{
	invertir();
	return 0;
}

