#include<bits/stdc++.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void insertionSort(int arr[],int n){

    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;

        while(j>=0 && arr[j] > temp){
            arr[j+1]=arr[j];
            j=j-1;
        }

        arr[j+1]=temp;
    }
}


int main(){

    //int input[] = {3,0,3,2,1,0};
    int input[] = {7,4,3,5,6,2};
    
    int n=6;
    insertionSort(input,n);
    display(input,n);
}
