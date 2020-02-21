#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

#define ll long long int

bool isEven(ll n){
    return n%2==0?true:false;
}

void prllArr(ll arr[],ll n){

    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void solve(ll arr[],ll n){

    ll even[n];
    ll odd[n];

    if(isEven(arr[0])){
        even[0]=1;
        odd[0]=0;
    }else{
        odd[0]=1;
        even[0]=0;
    }


    for(ll i=1;i<n;i++){
        if(isEven(arr[i])){
            even[i]=even[i-1]+1;
            odd[i]=odd[i-1];
        }else{
            odd[i]=odd[i-1]+1;
            even[i]=even[i-1];
        }
    }

    //prllArr(odd,n);
    //prllArr(even,n);


    // Dynamic Solution for the Subarray Problem

    ll dp[n][n];

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            dp[i][j]=0;
        }
    }

    ll temp1=0;
    ll temp2=0;

    for(ll i=0;i<n;i++){    // even
        for(ll j=i+1;j<n;j++){  // odd
            if((even[j]-temp1)==(odd[j]-temp2)){
                dp[i][j]=1;
            }
        }

        temp1=even[i];
        temp2=odd[i];
    }

    ll ans = 0;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            //cout<<dp[i][j]<<" ";
            if(dp[i][j])
                ans++;
        }
        //cout<<endl;
    }

    cout<<ans<<endl;

}


int main(){
    
    //fast;

    ll n=4;
    cin>>n;
    ll arr[n];// = {1,2,1,2};
    for(ll i=0;i<n;i++) cin>>arr[i];

    solve(arr,n);
}
