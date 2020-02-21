#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll maxElem(ll arr[],ll n){
    ll mx=arr[0];
    for(ll i=1;i<n;i++){
        if(arr[i] > mx)
            mx=arr[i];
    }
    return mx;
}

int main(){

    const ll aSize = 100001;
    ll cnt[aSize];

    for(ll i=0;i<aSize;i++){
        cnt[i]=0;
    }

    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        cnt[arr[i]]++;
    }

    ll m = maxElem(arr,n);


    ll dp[m+1];
    dp[0]=0;
    dp[1]=cnt[1];

    for(ll i=2;i<=m;i++){
        dp[i]= max(dp[i-1],dp[i-2]+cnt[i]*i);
    }

    cout<<dp[m]<<endl;

}
