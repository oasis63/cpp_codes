#include<bits/stdc++.h>
using namespace std;

/*
 only squares of prime numbers have exactly three distinct positive divisors.
 ex:- 4,9,25,169
*/

#define ll unsigned int
#define SIZE  1000001


bool isPrime(ll n){
    
    if( n==1 )
        return false;

    ll t = sqrt(n);

    for(ll i=2;i<=t;i++){
        if (n%i==0){
            return false;
        }
    }

    return true;
}


int main(){
    
    // setPrimes(); 
     
    // printArr(primes,SIZE);

    // outputToFile();
    int n;cin>>n;
    ll a,b;
    while(n--){
        cin>>a>>b;
        for(ll i=a;i<=b;i++){
            if(isPrime(i)){
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
}