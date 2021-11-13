#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const ull mod = 1000000007;


ull binomialCoeff(ull n, ull k)
{
    ull C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (ull i = 1; i <= n; i++) {
        for (ull j = min(i, k); j > 0; j--)
            C[j] = (C[j]%mod + C[j - 1]%mod)%mod;
    }
    return C[k];
}


int main(){

  ull tc,n,m;
  cin>>tc;
  while(tc--){
    cin>>n>>m;
    cout<<binomialCoeff(m+n-1,n)<<endl;
  }

  return 0;
}
