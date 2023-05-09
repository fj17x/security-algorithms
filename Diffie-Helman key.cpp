#include<cmath>
#include<iostream>
using namespace std;

long int compute(long int a,long int b, long int c){
	if(b==1)
		return a;
	else return ((long int)pow(a,b) % c);	
}

int main(){
	
	long int p,g,x,y,R1,R2,keya,keyb;
	cout<<"Enter p,g,x and y: ";
	cin>>p>>g>>x>>y;

	R1= compute(g,x,p);
	R2= compute(g,y,p);
	
	keya = compute(R1,x,p);
	keyb = compute(R2,y,p);
	
	cout<<"Secret key for A is :"<<keya;
	cout<<"\nSecret key for B is :"<<keyb;
}


