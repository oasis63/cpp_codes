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

// write output to file 

void outputToFile(){
  ofstream myfile;
  myfile.open ("primesOutput.txt");
  myfile << "Number   and   isPrime\n";

  for(ll i=0;i<SIZE;i++){
    myfile<<i<<" "<<primes[i]<<endl;
  }
  myfile.close();

  myfile.open("primeSet.txt");
  myfile<<"Primes "<<endl;
  for(ll p : primeSet){
    myfile<<p<<endl;
  }

  cout<<"written to the file"<<endl;
  myfile.close();
}


int main(){
    
    setPrimes(); 
     
    // printArr(primes,SIZE);

    // outputToFile();
}