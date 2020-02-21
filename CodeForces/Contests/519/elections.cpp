#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    int opp=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        opp += arr[i];
    }

    sort(arr,arr+n);

    int k=arr[n-1];

    while(1){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += (k-arr[i]);
        }
        if(sum > opp){
            cout<<k<<endl;
            break;
        }
        k++;
    }



}
