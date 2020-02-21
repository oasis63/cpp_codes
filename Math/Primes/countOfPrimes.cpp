// Number of primes between two given numbers
#include <bits/stdc++.h>
using namespace std;

#define range 100001

int primeArr[range];

void setPrime(){

    primeArr[0]=0;
    primeArr[1]=0;

	for(int i=2;i<range;i++)
		primeArr[i]=1;


	for(int i=2;i<=sqrt(range);i++){
		if(primeArr[i]){
			for(int j=i*i;j<range;j+=i)
				primeArr[j]=0;
		}
	}



	for(int i=2;i<range;i++){
		primeArr[i]+=primeArr[i-1];
	}
}

int main(){

    setPrime();

	int first=2;
	int last=7;

	int count = primeArr[last] - primeArr[first-1];

	cout<<count<<endl;
}
