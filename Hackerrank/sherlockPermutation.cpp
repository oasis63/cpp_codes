#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const ull mod = 1000000007;



ull combinations(ull n,ull r){

  ull dp[n+1][r+1];

  for(ull j=0;j<=r;j++)
    dp[0][j]=0;
  for(ull i=0;i<=n;i++)
    dp[i][0]=1;

  for(ull i=1;i<=n;i++){
    for(ull j=1;j<=r;j++){
      dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
    }
  }



  return dp[n][r];

}

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

// both the above methods passes all the testcases


int main(){

  ull tc,n,m;
  cin>>tc;
  while(tc--){
    cin>>n>>m;
    cout<<combinations(m+n-1,n)<<endl;
  }

  return 0;
}
