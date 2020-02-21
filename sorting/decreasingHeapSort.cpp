#include<bits/stdc++.h>
using namespace std;

void displayArr(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}


void heapify(vector<int> &a,int n,int i){
    int small = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(a[left] < a[small] && left < n)
        small=left;
    if(a[right] < a[small] && right < n)
        small = right;

    if(small!=i){
        swap(a[small],a[i]);
        heapify(a,n,small);
    }
}

void heapSort(vector<int> &a,int n){

    // min-heapify  
    for(int i=(n/2)-1;i>=0;i--){
        // displayArr(a);
        heapify(a,n,i);
    }

    cout<<endl;

    for(int i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        // displayArr(a);
        heapify(a,i,0);  // i= number of remaining elements
    }
}


int main(){
    vector<int> a{31,1,21,9,10,12,18,3,2,8,7};

    heapSort(a,11);

    displayArr(a);
}
