#include<bits/stdc++.h>
using namespace std;


int nonAdjMaximumSum(int arr[],int n){

    int a = 0;
    int b = 0;

    for(int i=0;i<n;i++){
        int temp_b =  b > a ? b : a;
        a = b + arr[i];
        b = temp_b;
    }

    return b>a?b:a;
}

int main(){        
    int arr[] = {-2,1,3,-4,5};
    // int arr[] = {-4,5,7,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<nonAdjMaximumSum(arr,n)<<endl;
    return 0;
}