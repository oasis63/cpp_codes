#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n){
    sort(arr,arr+n);

    int minSum = INT_MAX;
    int maxSum = INT_MIN;

    int i=0,temp;
    int j=n-1;

    while(i<j){
        temp = arr[i]+arr[j];
        if(temp < minSum)
            minSum = temp;
        if(temp>maxSum)
            maxSum = temp;
        i++;
        j--;
    }

    return (maxSum-minSum);
}

int main(){

    //int arr[] = {2,6,4,3};
    int arr[] = {11,4,3,5,7,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr,n);
}
