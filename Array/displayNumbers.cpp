#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

ll mod = 1e9+7;

ll dyna(ll n){

    ll dp[n+1];
    dp[0]=1;
    dp[1]=2;

    for(ll i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }

    for(ll i=0;i<=n;i++){
        cout<<01010*i<<"\t"<<i<<"\t"<<dp[i]<<"\t"<<i*2<<"\t"<<dp[i]*2<<"\t"<<i*3<<dp[i]*3<<"\t"<<01010*i<<endl;
    }

    return dp[n];
}

int main() {

    ll n=10000;
    //cin>>n;
    cout<<dyna(n)<<endl;
    


    return 0;
}
