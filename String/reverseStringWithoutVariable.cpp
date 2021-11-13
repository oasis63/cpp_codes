#include<bits/stdc++.h>
using namespace std;

/*
	Reverse a string without using temporary variable
*/

/* 
	//For Reference 

	int a = 5;
	int b = 3;
	a = a+b;  8
	b=a-b;   5
	a=a-b;  3
*/

void reverseString(string str){

	int start=0;
	int end = str.length()-1;

	while(start < end){
		str[start] ^= str[end];
		str[end] ^= str[start];
		str[start] ^= str[end];
		
		start++;
		end--;
	}

	cout<<str<<endl;

}

int main(){
	
	reverseString("hello");
	return 0;
}

