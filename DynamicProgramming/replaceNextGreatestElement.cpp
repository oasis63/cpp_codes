#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {16,17,4,3,5,2};

    int n=6;

    int mx = arr[n-1];  // 2
    arr[n-1] = -1;
    int temp=arr[n-2];  // 5
    arr[n-2]=mx;

    if(temp>mx)
        mx=temp;  // 5

    for(int i=n-3;i>=0;i--){
            int prev=arr[i];
            arr[i]=mx;   // 5
            if(prev > mx)
                mx=prev;
    }

    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";

}
