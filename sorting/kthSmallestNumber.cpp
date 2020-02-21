#include<bits/stdc++.h>
using namespace std;


void display(vector<int> arr){
    int n = arr.size();

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void kSmallestElement(vector<int> &arr,int k){
    int n = arr.size();
    int idx = k;

    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-i-1;j++){
            if(arr[j] < arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }

        k--;

        if(k==0){
            cout<<"kth smallest element is : "<< arr[n-idx]<<endl;
            // break;
        }
    }
}


int main(){
    
    vector<int> input {7,4,3,5,6,2};

    int k = 3;
    kSmallestElement(input,k);
    display(input);
}
