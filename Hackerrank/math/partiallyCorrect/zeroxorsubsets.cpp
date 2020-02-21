#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long

/*
    all test cases are not passing
*/


ll power(ll x,ll n,ll mod){
   // x=x%mod;
    ll res=1;
    while(n > 0){
        if(n&1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}

int main(){

    ll mod = 1000000007;

    ll tc;
    cin>>tc;

    while(tc--){
        ll n;
        cin>>n;

        ll temp = (power(2,n,mod-1)-n)%(mod-1);
        cout<<power(2,temp,mod)<<endl;

    }

}
