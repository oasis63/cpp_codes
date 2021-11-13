#include<bits/stdc++.h>
using namespace std;

// base62

string base62_encode(int num){

	string pattern = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	string encoded_str = "";

	while(num > 0){
		encoded_str = encoded_str + pattern[num%62];
		num /= 62;
	}

	return encoded_str;
}

int main(){
	
	string encoded_str = base62_encode(999);

	cout<<encoded_str<<endl;

	return 0;
}