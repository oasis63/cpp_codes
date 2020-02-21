#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define mod 1000000007

ll gcd(ll a,ll b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}
ll gcdArray(ll a[],ll n){
    ll ans=a[0];

    for(ll i=0;i<n;i++){
        ans=gcd(a[i],ans);
    }

    return ans;
}

// binary modular exponentiation

ll binModExpo(ll x,ll n){

    if(n==0)
        return 1;
    else if(n%2==0)
        return binModExpo((x*x)%mod,n/2)%mod;
    else
        return (x*binModExpo((x*x)%mod,(n-1)/2))%mod;
}





int main(){
    ios_base::sync_with_stdio(false);
    
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll g = gcdArray(a,n);

    ll f=1;

    for(ll i=0;i<n;i++){
        f=(f*a[i])%mod;
    }

    cout<<binModExpo(f,g)<<endl;
}
