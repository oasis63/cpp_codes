#include<bits/stdc++.h>
using namespace std;

/*
	You are given an integer n no less than 12, 
	express it as a sum of two composite numbers.
*/

#define MAX_SIZE 1000001

int primes[MAX_SIZE] ;

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void setPrimes(){

	for(int i=0;i<MAX_SIZE;i++){
		primes[i]=1;
	}

	primes[0]=0;
	primes[1]=0;

	for(int i=2;i<=sqrt(MAX_SIZE);i++){
		if(primes[i]){
			for(int j=i*i;j<MAX_SIZE;j+=i){
				primes[j]=0;
			}
		}
	}
}

void solve(int n){
	int a=0,b=0;

	for(a=4;a<n;a++){
		b=n-a;
		if(!primes[a] && !primes[b]){
			cout<<a<<" "<<b<<endl;
			break;
		}
	}
}

int main(){
		
	setPrimes();

	int n;cin>>n;
	solve(n);

	return 0;
}