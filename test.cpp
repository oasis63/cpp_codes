#include<bits/stdc++.h>
using namespace std;

/*
 only squares of prime numbers have exactly three distinct positive divisors.
 ex:- 4,9,25,169
*/

#define ll long long
#define SIZE  1000001
bool primes[SIZE];

set<ll> primeSet;

void setPrimes(){

    for(ll i=0;i<SIZE;i++){
        primes[i]=true;
    }

    primes[0]=false;
    primes[1]=false;

    for(ll i=2;i<=sqrt(SIZE);i++){
    
       if(primes[i]){
            for(ll j=i+i;j<SIZE;j+=i){
                primes[j]=false;
            }
       }
        
    } 

    for(ll i=0;i<SIZE;i++){
        if(primes[i]){
            primeSet.insert(i);
        }
    }

} 

template<class X>
void printArr(X arr[],ll n){
    for(ll i=0;i<n;i++){
        cout<<i<<" "<<arr[i]<<endl;
    }
    cout<<endl;
}


int main(){
    
    setPrimes(); 
     

}