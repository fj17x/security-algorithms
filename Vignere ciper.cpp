#include<iostream>
#include<string>
using namespace std;


void encryption(string pt, string key, string &ct){
	int k;
	for(int i=0,j=0;i<pt.length();i++,j++){
		if(j>=key.length()){
			j=0;
		}
		k=(key[j] - 'a')%26;
		if(isupper(pt[i])){
			ct+= (pt[i]-'A' + k)%26 + 'A';
		}
		else if(islower(pt[i])){
			ct+= (pt[i] - 'a' + k)%26 + 'a';
		}
		else{
			ct+= pt[i];
			j--;
		}	
	}
}

void decryption(string ct,string key,string&pt){
	int k;
	for(int i=0,j=0;i<ct.length();i++,j++){
		if(j>=key.length()){
			j=0;
		}
		k=(key[j] - 'a')%26;
		if(isupper(ct[i])){
			pt+= (ct[i] - 'A' - k + 26)%26 + 'A';
		}
		else if(islower(ct[i])){
			pt+= (ct[i] - 'a' - k + 26)%26 + 'a';
		}
		else{
			pt+= ct[i];
			j--;
		}
	}
}

int main(){
	string pt,key,ct, dpt;
	cout<<"Enter the plaintext and the key(lowercase): ";
	getline(cin,pt);
	getline(cin,key);
	encryption(pt,key,ct);
	cout<<"The encrypted text is: "<<ct;
	decryption(ct,key,dpt);
	cout<<"\nThe decrypted text is: "<<dpt;
}