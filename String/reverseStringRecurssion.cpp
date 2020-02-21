#include<bits/stdc++.h>
using namespace std;


string reverse(string str){
	if(str.length() == 0){
		return str;
	}
	return str[str.length()-1] + reverse(str.substr(0,str.length()-1));
}

int main(){
	
	cout<<reverse("hello")<<endl;

	return 0;
}