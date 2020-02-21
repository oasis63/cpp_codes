#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll fact[1000010];
ll mod=1000000007;

// Factorial for large integer values



ll calcFact(ll range){

    fact[0]=1;

    for(ll i=1;i<=range;i++){
        fact[i]=fact[i-1]*i;
        fact[i]=fact[i]%mod;
    }

}

int main(){

    calcFact(100);

    cout<<fact[8]<<endl;


    cout<<fact[50]<<endl;

}



