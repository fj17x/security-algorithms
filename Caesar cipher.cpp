#include <iostream>
#include <string>
using namespace std;

string encryption(string,int);
string decryption(string,int);

int main(){
	int key;
	string message;
	
	cout<<"Enter the key: ";
	cin>>key;
	
	cout<<"Enter the string: ";
	cin>>message;

	string result = encryption(message, key);
	decryption(result, key);
}

string encryption(string message, int key){

	string t;
	for(int i=0;i<message.size();i++){
		if(isupper(message[i])){
			t+= (message[i] - 'A' + key)%26 + 'A';
		}	
		else{
			t+= (message[i] - 'a' + key)%26 + 'a';
		}
	}
	cout<<"\nThe encrypted message is: "<<t;
	return t;
}

string decryption(string message,int key){
	
	string t;
	for(int i=0;i<message.size();i++){
		if(isupper(message[i])){
			t+= (message[i] - 'A' - key + 26)%26 + 'A';
		}	
		else{
			t+= (message[i] - 'a' - key + 26)%26 + 'a';
		}
	}
	cout<<"\nThe decrypted message is: "<<t;
}
