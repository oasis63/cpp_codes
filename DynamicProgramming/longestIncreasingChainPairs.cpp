#include<bits/stdc++.h>
using namespace std;

//Maximum Length Chain of Pairs

/*
    Before applying Longest Increasing Subsequence ...
    Sort given pairs in increasing order of first (or smaller) element.
*/
int maxChainLength(vector<pair<int,int>> arr,int n){

    int mcl[n];

    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++)
        mcl[i]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i].first > arr[j].second && mcl[i] < mcl[j]+1)
                mcl[i]=mcl[j]+ 1;
        }
    }

    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(mcl[i] > mx)
            mx=mcl[i];
    }
    return mx;
}

int main(){

    vector<pair<int,int>>arr= { {5, 24}, {15, 25},{27, 40}, {50, 60} };

    int n = arr.size();

    //Sort given pairs in increasing order of first (or smaller) element.

    cout<<"Maximum Length Chain of Pairs is : "<<maxChainLength( arr, n ) <<endl;


    return 0;
}
