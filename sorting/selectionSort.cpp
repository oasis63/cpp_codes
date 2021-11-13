#include<bits/stdc++.h>
using namespace std;

/*
Selection Sort has least number of swaps
*/

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void selectionSort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        int min=i;
        
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        if(min!=i){
            swap(arr[i],arr[min]);
        }
    }
}


int main(){

    int input[] = {3,0,3,2,1,0};
    //int input[] = {7,4,3,5,6,2};
    
    int n=6;
    selectionSort(input,n);
    display(input,n);
}
