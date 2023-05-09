#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a,int h){
	int temp;
	while(1){
		temp = a%h;
		if(temp==0){
				return h;
		}
		a=h;
		h=temp;
	}
}


int main(){

	double p=3;
	double q=7;
	double n = p*q;
	double phi = (p-1) * (q-1);
	double e=2;
	
	while(e<phi){
		if(gcd(e,phi) == 1)
		{
			break;
		}
		else{
			e++;
		}
	}
	
	int k=2;
	double d = (1+(k*phi)/e);
	double msg = 12;
	
	cout<<"Message data: "<<msg ;
	double c = pow(msg,e);
	c= fmod(c,n);
	cout<<"Encrypted data: "<<c;
	
	double m = pow(c,d);
	m= fmod(m,n);
	cout<<"\Decrypted data: "<<m;

}

