#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n){
//    n--;
    sort(arr,arr+n-1);
    int ans = 0;
    if(arr[0]!=1){
        return 1;
    }
    for(int i=1;i<n-1;i++){
        if(arr[i]-arr[i-1] != 1){
            return arr[i-1]+1;
        }
    }
    return n;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;cin>>n;
        int arr[n-1];
        for(int i=0;i<n-1;i++){
            cin>>arr[i];
        }
        cout<<solve(arr,n)<<endl;
    }
    return 0;
}
