#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define SIZE  100001

bool primes[SIZE];

vector<int> primeNums;

void setPrimes(){

    for(ll i=0;i<SIZE;i++){
        primes[i]=true;
    }

    primes[0]=false;
    primes[1]=false;

    for(ll i=2;i<=sqrt(SIZE);i++){
        for(ll j=i*i;j<SIZE;j+=i){
            primes[j]=false;
        }
    }

    for(ll i=2;i<SIZE;i++){
        if(primes[i]){
            primeNums.push_back(i);
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
    
    int tc;
    cin>>tc;

    while(tc--){

        setPrimes();
        
        int n;
        cin>>n;

        int count=0;

        for(int i=0;primeNums[i]<=n;i++){

            int sum = primeNums[i];

            for(int j=i+1;primeNums[j]<=n;j++){
                sum += primeNums[j];
                if(primes[sum]){
                    count++;
                    primes[sum] = false;
                }
            }

        }
      
      cout<<count<<endl;


    }

    return 0;
}