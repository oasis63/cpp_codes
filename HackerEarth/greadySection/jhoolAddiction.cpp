#include<bits/stdc++.h>
using namespace std;


void solve(int arr[],int n,int k){


    sort(arr,arr+n);
    int mn=INT_MAX;
    int mx=INT_MIN;

    for(int i=0,j=n-1;i<=j;i++,j--){
        int sum = arr[i]+arr[j];
        //cout<<sum<<endl;

        if(sum < mn)
            mn = sum;

        if(sum > mx)
            mx=sum;
    }

    int diff = mx-mn;

    cout<<diff<<endl;

    if(diff > k)
        cout<<"No more girlfriends!"<<endl;
    else if(diff == k)
        cout<<"Lucky chap!"<<endl;
    else
        cout<<"Chick magnet Jhool!"<<endl;

}


int main(){

    int tc;cin>>tc;
    while(tc--){
        int n,k;
        cin>>n>>k;

        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        solve(arr,n,k);
    }

}
