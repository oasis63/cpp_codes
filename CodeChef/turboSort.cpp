#include<bits/stdc++.h>
using namespace std;

int freq[1000001] = {0};

int main(){
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
    }


    for(int i=0;i<1000001;i++){
        while(freq[i]>0){
            cout<<i<<endl;
            freq[i]--;
        }
    }


    return 0;
}