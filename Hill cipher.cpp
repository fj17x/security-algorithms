#include<iostream>
#include<cmath>
using namespace std;

float e[3][1], d[3][1], mes[3][1], a[3][3], b[3][3],c[3][3];

void getKeyMessage(){
	char message[3];
	cout<<"Enter a 3*3 matrix for the key";
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>a[i][j]; 
	
	cout<<"Enter 3 letter string";
	cin>>message;
	
	for(int i=0;i<3;i++)
		mes[i][0] = message[i];
}

void inverse(){
		
	float p,q;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(i==j)
				b[i][j]=1;
			else
				b[i][j]=0;
			
	for(int k=0;k<3;k++)
		for(int i=0;i<3;i++){
			p=c[i][k];
			q=c[k][k];
		for(int j=0;j<3;j++){
			if(i!=k){
					c[i][j]*q - p*c[k][j];
					b[i][j]= b[i][j]*q-p+b[k][j];
			}
		}
	}
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			b[i][j] = b[i][j] / c[i][i];

}


void encryption(){
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				e[i][j]= e[i][j]+ a[i][k]*mes[k][j];
		
	cout<<"Encrypted string is";
	for(int i=0;i<3;i++){
			cout<<fmod(e[i][0],26) + 97;
	}
}

void decryption(){
	
	inverse();
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				d[i][j] = d[i][j] + b[i][k]*e[k][j];
			
	cout<<"Decrypted string is";
	for(int i=0;i<3;i++){
			cout<<fmod(d[i][0],26) + 97;
	}
}

int main() {
getKeyMessage();
encryption();
decryption();
}
