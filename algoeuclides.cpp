#include <iostream>
#include <time.h>
using namespace std;

int mcd(int a, int b){
	while(a!=b){
		if(a>b){
			a=a-b;
		}
		else{
			b=b-a;
		}
	}
	return a;
}

int mcd2(int a, int b){
	int r=a%b;
	if(r==0){
		return b;
	}
	else{
		a=b;
		b=r;
	}
	return mcd2(a,b);

}
int main(int argc, char *argv[]) {
	cout<<mcd(412,260)<<endl;
	cout<<mcd2(412,260);
	return 0;
}

