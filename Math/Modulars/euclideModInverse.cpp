#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 1000000007;
ll fact[100001],ifact[100001];

ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    // Base Case
    if (a == 0) {
        *x = 0;
        *y = 1; 
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

ll modInverse(ll a) { 
    ll x, y; 
    ll g = gcdExtended(a, mod, &x, &y);
    // m is added to handle negative x
    ll res = (x%mod+ mod) % mod;
    return res;
}

ll inv(ll x,ll  y, ll p, ll q, ll r, ll s) {

    if(y==0) 
        return (p%MOD+MOD)%MOD;
    return inv(y, x%y, r, s, p-r*(x/y), q-s*(x/y));
}

int main(){

    

}