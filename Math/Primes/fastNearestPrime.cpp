#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define SIZE  1001
bool primes[SIZE];

void setPrimes(){

    for(ll i=0;i<SIZE;i++){
        primes[i]=true;
    }

    primes[0]=false;
    primes[1]=false;

    for(ll i=2;i<=sqrt(SIZE);i++){
    
       if(primes[i]){
          for(ll j=i*i;j<SIZE;j+=i){
            primes[j]=false;
          }
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
  printArr<bool>(primes,100);

  int num = 51;
  

  // nearest prime

  if(primes[num]){
    cout<<num<<endl;
  }else{

    int s = num-1;    // smaller
    int b = num+1;    // bigger

    while(1){
        if(primes[s]){
          cout<<s<<endl;
          break;
        }
        if(primes[b]){
          cout<<b<<endl;
          break;
        }
        s--;
        b++;
    }
  }






  return 0;
}