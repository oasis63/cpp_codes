#include<bits/stdc++.h>
using namespace std;


void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void bubbleSort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swapped = true;
                swap(arr[j],arr[j+1]);
            }
        }
        // list is sorted .. so break
        if(!swapped)
            break;

    }
}


int main(){

    //int input[] = {3,0,3,2,1,0};
    int input[] = {7,4,3,5,6,2};
    
    int n=6;
    bubbleSort(input,n);
    display(input,n);
}
