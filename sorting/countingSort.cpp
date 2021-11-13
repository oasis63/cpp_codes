#include<bits/stdc++.h>
using namespace std;

int findMax(int a[],int n){
    int mx = INT_MIN;

    for(int i=0;i<n;i++){
        if(a[i] > mx){
            mx=a[i];
        }
    }
    return mx;
}

// counting sort

int main(){

    int input[] = {3,3,4,2,1,2};

    int n=6;

    int freq[5];

    for(int i=0;i<5;i++){
        freq[i]=0;
    }

    for(int i=0;i<n;i++){
        freq[input[i]] ++;
    }

     for(int i=1;i<5;i++){
        freq[i] = freq[i] + freq[i-1];
    }

    // temporary storing array

    int temp[6];

    for(int i=0;i<n;i++){
        temp[freq[input[i]]-1] = input[i];
        freq[input[i]]--;
    }


    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }

    cout<<endl;
}
