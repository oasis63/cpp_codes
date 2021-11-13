#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod=1e9+7;

const ll maxLen=1e5+1;

ll fact[maxLen];

ll getFact(ll i){  // using recursion
  if(i==0 || i==1)
    fact[i]=1;
  else if(fact[i]==0)    // no repeated calculation   /..... tabulation Bottom-Up
    fact[i]=(getFact(i-1)*i)%mod;

    return fact[i];
}

int  main()
{
   memset(fact,0,maxLen);  // setting all values to 0

    ll t,n;cin>>t;
    while(t--){
        cin>>n;
        cout<<getFact(n)<<endl;
    }
}
