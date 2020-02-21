#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

ll mod = 1e9+7;

ll rec(ll n){
    if(n==0)
        return 1;
    if(n==1)
        return 2;
    return rec(n-1)+rec(n-2);
}


ll dyna(ll n){

    ll dp[n+1];
    dp[0]=1;
    dp[1]=2;

    for(ll i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }

    for(ll i=0;i<=n;i++){
        cout<<i<<" "<<dp[i]<<endl;
    }

    return dp[n];
}

int main() {

    ll tc;
    cin>>tc;
    while(tc--){
        ll n;cin>>n;
        cout<<dyna(n)<<endl;
    }


    return 0;
}
