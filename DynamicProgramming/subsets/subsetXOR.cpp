/*
    Count number of subsets having a particular XOR value

    Dynamic Programming ;

     a number m such that m = pow(2,(log2(max(arr))+1))­ – 1.
     This number is actually the maximum value any XOR subset will acquire

    dp[i][j] equals to the number of subsets having
    XOR value j from subsets of arr[0…i-1].
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll findMax(ll arr[],ll n){
    ll mx = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > mx){
            mx=arr[i];
        }
    }
    return mx;
}

// count the number of subsets

ll countXORSubsets(ll arr[],ll n,ll k){


    ll mx = findMax(arr,n);

    // maximum XOR value in the subsets
    ll m = pow(2,(log2(mx)+1))-1;


    ll dp[n+1][m+1];
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }

    dp[0][0] = 1; //  Empty Subset has XOR 1

    // fill the table

    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j^arr[i-1]];
        }
    }

    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][k];
}

int main(){

    ll arr[] = {0,1,2};
    ll n=3;
    ll k=0;

    ll ans = countXORSubsets(arr,n,k);

    cout<<"\nNumber of subsets having XOR value " <<k  <<"  : ";
    cout<<ans<<endl;

    return 0;
}






