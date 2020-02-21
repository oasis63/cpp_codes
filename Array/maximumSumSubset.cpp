#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    ll n;cin>>n;
    ll arr[n];

    for(ll i=0;i<n;i++) cin>>arr[i];

    ll sum = 0;
    ll count = 0;
    ll mxElem = INT_MIN;

    for(ll i=0;i<n;i++){
        if(arr[i] >= 0){  // add all the non-negative numbers 
            sum += arr[i];
            count++;
        }
    }

    if(count==0){
        // only negative numbers in the input file
        
        for(ll i=0;i<n;i++){  // take the maximum of the negative numbers 

            if(arr[i] > mxElem){
                mxElem = arr[i];
            }
        }
        
        cout<<mxElem<<" "<<1<<endl;
    }else{
        cout<<sum<<" "<<count;
    }

}
