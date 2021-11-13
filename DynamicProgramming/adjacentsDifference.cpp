#include<bits/stdc++.h>
using namespace std;

// Longest Increasing Subsequence

//Longest subsequence such that difference between adjacents is one

int findLIS(int arr[],int n){

    int lis[n];
    for(int i=0;i<n;i++)
        lis[i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && lis[i] < lis[j]+1)
                lis[i]=lis[j]+1;       // lis[i] = max(lis[i],lis[j]+1);
        }
    }

    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(lis[i] > mx)
            mx=lis[i];
    }
    return mx;
}

int commonDifference1(int arr[],int n){

    int lis[n];
    for(int i=0;i<n;i++)
        lis[i]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(abs(arr[i]-arr[j])==1 && lis[i] < lis[j]+1)
                lis[i] = lis[j]+1;
        }
    }

    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(lis[i] > mx)
            mx=lis[i];
    }
    return mx;


    // return *max_element(lis,lis+n);
}

int main(){

    int  arr[] = {3, 10, 2, 1, 20};
    int n=5;

    cout<<findLIS(arr,n)<<endl;



    int arr2[]  = {1, 2, 3, 2, 3, 7, 2, 1};
    n = sizeof(arr2)/sizeof(arr2[0]);

    cout<<commonDifference1(arr2,n)<<endl;


    return 0;
}
