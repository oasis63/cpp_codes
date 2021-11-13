#include<bits/stdc++.h>
using namespace std;

//Maximum Sum Increasing Subsequence

int maxSumIS(int arr[],int n){

    int sum[n];

    for(int i=0;i<n;i++)
        sum[i]=arr[i];

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && sum[i] < sum[j]+arr[i])
                sum[i]=sum[j]+arr[i];
        }
    }

    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(sum[i] > mx)
            mx=sum[i];
    }
    return mx;
}

int main(){

    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum sum increasing subsequence is : "<<maxSumIS( arr, n ) <<endl;


    return 0;
}
