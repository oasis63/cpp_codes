#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

int solve(int arr[],int n,int k){

    int sum = 0;
    int ans = 0;

    for(int i=0;i<n;i++){
        if(arr[i] <= k){
            sum += arr[i];
        }else{
            if(sum > ans)
                ans = sum;
            sum = 0;
        }
    }

    return ans;
}

int main(){

    int tc;cin>>tc;

    while(tc--){
        int n,k;cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        cout<<solve(arr,n,k)<<endl;

    }

//    int arr[] = {3,2,2,3,1,1,1,3};
//    int n = 8;
//    int k = 1;

    return 0;
}
