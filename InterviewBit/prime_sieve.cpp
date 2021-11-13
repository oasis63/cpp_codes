#include<bits/stdc++.h>
using namespace std;

void solve(int primes[],int n){

    primes[0]=0;
    primes[1] = 0;

    for(int i=2;i<=sqrt(n);i++){
        if(primes[i] == -1){
            for(int j=i*i;j<n;j+=i){
                primes[j] = 0;
            }
        }
    }
    
}


vector<int> sieve(int n) {
    int primes[n+1];
    vector<int> vect;
    
    memset(primes,-1,sizeof(primes));

    solve(primes,n);

    for(int i=0;i<=n;i++){
        cout<<primes[i]<<endl;
    }

    return vect;
}


int main(){
    
    vector<int> vect = sieve(7);

    cout<<vect.size()<<endl;
    

    return 0;
}