#include<bits/stdc++.h>
using namespace std;

/*

 only squares of prime numbers have exactly three distinct positive divisors.
 ex:- 4,9,25,169

*/

#define ll long long
#define SIZE  1000001
bool primes[SIZE];

set<ll> primNum;

void setPrimes(){

    for(ll i=0;i<SIZE;i++){
        primes[i]=true;
    }

    primes[0]=false;
    primes[1]=false;

    for(ll i=2;i<=sqrt(SIZE);i++){
    
       if(primes[i]){
        // primNum.insert(i);
         for(ll j=i*i;j<SIZE;j+=i){
            primes[j]=false;
        }
       }
        
    } 

    for(ll i=0;i<SIZE;i++){
        if(primes[i]){
            primNum.insert(i);
        }
    }

}


int main(){
    
    setPrimes(); 
    ll n,num;
    cin>>n;
    for(ll i=0;i<n;i++){

        cin>>num;
        ll j = sqrt(num);
        
        
        if(j*j == num){

            if(primNum.find(j)!=primNum.end()){
                cout<<"YES"<<endl;
             }else{
                cout<<"NO"<<endl;
             }

        }else{
            cout<<"NO"<<endl;
        }
         
    }

}