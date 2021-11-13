#include<bits/stdc++.h>
using namespace std;


int modExpo(int a,int n,int m){
	if( n== 0)
		return 1;
	else if(n%2==0)
		return modExpo((a*a)%m,n/2,m);
	else
		return (a*(modExpo((a*a)%m,(n-1)/2,m)))%m;
}


int modInverse(int a,int p){
	return modExpo(a,p-2,p);   // using fermat's Therorem 
}



int main(){
		       	
	/*
		Find  (a/b)%p   where p is a prime 
		Ex:- 
			(2/5)%3
	*/	

	int a,b,p;
	cin>>a>>b>>p;

	int res = (a%p)*modInverse(b,p);    

	cout<<res<<endl;

	return 0;
}