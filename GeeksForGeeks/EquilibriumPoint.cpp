#include<bits/stdc++.h>
using namespace std;

#define ll long int

ll findEquilibriumPoint(ll arr[],ll n){

    /*if(n==1)
        return 1;*/

    ll cumm[n];
    cumm[0] = arr[0];
    for(int i=1;i<n;i++)
        cumm[i] = cumm[i-1] + arr[i];
    
    for(int i=0;i<n;i++){
        
        if(i==0){
            if((cumm[n-1]-arr[i]) == 0){
                return i+1;
            }
        }else if(i==n-1){
            if(cumm[n-2] == 0)
                return n;
        }else{
            if((cumm[n-1]-cumm[i])==(cumm[i]-arr[i]))
                return i+1;
        }
    }


    return -1;
}

int main(){
    
    ll tc;
    cin>>tc;
    
    while(tc--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll ans = findEquilibriumPoint(arr,n);
        
        cout<<ans<<endl;
    }

    return 0;
}