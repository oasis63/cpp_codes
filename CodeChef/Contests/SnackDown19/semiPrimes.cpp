#include<bits/stdc++.h>
using namespace std;

#define ll int

#define SIZE  201
ll primes[SIZE];
ll semiPrimes[SIZE];
ll sumSemiPrimes[SIZE];


void printArr(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void setPrimes(){

    for(ll i=0;i<SIZE;i++){
        primes[i]=1;
    }

    primes[0]=0;
    primes[1]=0;

    for(ll i=2;i<=sqrt(SIZE);i++){
    
        for(ll j=i*i;j<=SIZE;j+=i){
            primes[j]=0;
        }
        
    }
}

void setSemiPrimes(){
	//expressed  as product of two different primes 

	semiPrimes[0]=0;
	semiPrimes[1]=0;

	for(ll i=2;i<SIZE;i++){

		if(primes[i]){
			semiPrimes[i]=0;

		}else{
			bool flag = true;
			for(ll j=2;j<i;j++){
				if(primes[j] == 1 && i%j==0 && i/j!=j && primes[i/j]){
					semiPrimes[i]=1;
					flag=false;
					break;
				}
			}
			if(false)
				semiPrimes[i]=0;
		}
	}
}

void setSumSemiPrimes(){

	// sum of two semi-primes (not necessarily distinct) 

	sumSemiPrimes[0]=0;
	sumSemiPrimes[1]=0;
	sumSemiPrimes[2]=0;

	for(ll i=3;i<SIZE;i++){
		bool flag=true;
		for(ll j=2;j<i;j++){
			if(semiPrimes[j]){
				ll temp = i-j;
				if(semiPrimes[temp]){
					flag=false;
					sumSemiPrimes[i]=1;
					break;
				}
			}
		}
		if(flag)
			sumSemiPrimes[i]=0;
	}



}


int main(){
	
	setPrimes();
	setSemiPrimes();
	setSumSemiPrimes();

	/*for(int i=0;i<SIZE;i++){
		cout<<i<<" "<<primes[i]<<" "<<semiPrimes[i]<<" "<<sumSemiPrimes[i]<<endl;
	}*/

	int tc,n;
	cin>>tc;
	assert(tc>=1 && tc<= 200);

	while(tc-- > 0){
		cin>>n;
		assert(n>=1 && n<= 200);
		if(sumSemiPrimes[n]){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	

	return 0;
}