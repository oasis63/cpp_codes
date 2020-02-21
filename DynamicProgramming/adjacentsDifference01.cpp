#include<bits/stdc++.h>
using namespace std;

// Longest Increasing Subsequence

//Maximum length subsequence with difference between adjacent elements as either 0 or 1

int findLIS(int arr[],int n){

    int lis[n];
    for(int i=0;i<n;i++)
        lis[i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && lis[i] < lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }

    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(lis[i] > mx)
            mx=lis[i];
    }
    return mx;
}

int commonDifference01(int arr[],int n){

    int lis[n];
    for(int i=0;i<n;i++)
        lis[i]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(abs(arr[i]-arr[j])<=1 && lis[i] < lis[j]+1)
                lis[i] = lis[j]+1;
        }
    }

    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(lis[i] > mx)
            mx=lis[i];
    }
    return mx;

}

int main(){

    int  arr[] = {3, 10, 2, 1, 20};
    int n=5;

    cout<<findLIS(arr,n)<<endl;



    //int arr2[]  = {2, 5, 6, 3, 7, 6, 5, 8};
    int arr2[]  = {-2, -1, 5, -1, 4, 0, 3};
    n = sizeof(arr2)/sizeof(arr2[0]);

    cout<<commonDifference01(arr2,n)<<endl;


    return 0;
}
