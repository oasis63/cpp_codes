#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod=1e9+7;

const ll maxLen=1e5+1;

ll fact[maxLen];


void setFact(){
    fact[0]=1;
    fact[1]=1;
    for(ll i=2;i<maxLen;i++){  // iteratic method
        fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
    }
}

int  main()
{
    setFact();
    ll t,n;cin>>t;
    while(t--){
        cin>>n;
        cout<<fact[n]<<endl;
    }
}
