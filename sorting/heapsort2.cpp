#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int n,int i){
    int large = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(a[left] > a[large] && left < n)
        large=left;
    if(a[right] > a[large] && right < n)
        large = right;

    if(large!=i){
        swap(a[large],a[i]);
        heapify(a,n,large);
    }
}

void heapSort(int a[],int n){

    // max-heapify  
    for(int i=(n/2)-1;i>=0;i--){
        heapify(a,n,i);
    }

    for(int i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        heapify(a,i,0);  // i= number of remaining elements
    }
}


int main(){
    int a[] = {31,1,21,9,10,12,18,3,2,8,7};

    heapSort(a,11);

    for(int i=0;i<11;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
