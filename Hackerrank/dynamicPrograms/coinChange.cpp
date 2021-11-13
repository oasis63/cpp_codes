#include<bits/stdc++.h>
using namespace std;

#define ll long long int

// Recursive Coin Change Solution 

ll recCoinChange(ll arr[],ll m,ll n){

//     if(n<0)
//         return 0;
//     if(n==0)
//         return 1;

//     if(m<=0 && n>=1)
//         return 0;

//     return recCoinChange(arr,m-1,n)+recCoinChange(arr,m,n-arr[m-1]);
    
    ll dp[n+1][m];

    ll x,y;

    for(ll i=0;i<=n;i++){
        for(ll j=0;j<m;j++){
            dp[i][j]=0;
        }
    }

    // when n is 0 ....
    for(ll j=0;j<m;j++){
        dp[0][j]=1;
    }

    for(ll i=1;i<=n;i++){
        for(ll j=0;j<m;j++){
            
            x = (i-arr[j] >= 0) ? dp[i-arr[j]][j]:0;
            y=(j>=1)?dp[i][j-1]:0;

            dp[i][j]=x+y;

        }
    }

    return dp[n][m-1];

}

int main(){
        
    ll m,n;
    cin>>n>>m;
    ll arr[m] ;//= {1,2,3};
    for(ll i=0;i<m;i++)
        cin>>arr[i];
    
    cout<<recCoinChange(arr,m,n)<<endl;

    return 0;
}