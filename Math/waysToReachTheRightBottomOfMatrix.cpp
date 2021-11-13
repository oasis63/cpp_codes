#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long

const ll mod = 1000000007;

ll binomialCoeff(ll n, ll k) { 
    ll C[k + 1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // nC0 is 1 
  
    for (ll i = 1; i <= n; i++) { 
        for (ll j = min(i, k); j > 0; j--) 
            C[j] = (C[j]%mod + C[j - 1]%mod)%mod; 
    } 
    return C[k]; 
} 


int main(){
  
  int tc;
  cin>>tc;
  ll m,n;
  while(tc--){
    cin>>m>>n;
    cout<<binomialCoeff(m+n-2,m-1)<<endl;
  }

  return 0;
}