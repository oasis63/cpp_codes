
// maximum sum increasing subsequence

#include<bits/stdc++.h>
using namespace std;

#define ll int

void reverse(ll arr[],ll beg,ll end,ll n){

    if(end >= n)
        end = n-1;

    while(beg<=end){
        swap(arr[beg],arr[end]);
        beg++;
        end--;
    }

}

void solve(ll arr[],ll n,ll t){

    for(int i=0;i<n;i+=t){
        reverse(arr,i,i+t-1,n);
    }
}



int main(){
    //code
    
    int tc;
    cin>>tc;
    
    while(tc--){
        int n,t;cin>>n>>t;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cout<<endl;
       
       solve(arr,n,t);
    
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
       
    }
    
    return 0;
}