#include<bits/stdc++.h>
using namespace std;


int findLis(int arr[],int n){

    int lis[n];
    for(int i=0;i<n;i++)
        lis[i]=1;


    vector<vector<int>> subElems(n);    // size of the vector of vectors


    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1 ){
               subElems[i].push_back(arr[j]);
                lis[i]=lis[j] +1;
            }
        }
        subElems[i].push_back(arr[i]);
    }

    int mx=0;
    int idx=0;

    for(int i=0;i<n;i++){
        if(lis[i]>mx){
            mx=lis[i];
            idx=i;
        }
    }

    cout<<endl;

    int len = subElems[idx].size();

   // cout<<len<<endl;

    for(int i=0;i<len;i++){
        cout<<subElems[idx][i]<<" ";
    }

    cout<<endl;

    return mx;
}

int main(){

    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of lis is "<<findLis( arr, n )<<endl;


}
