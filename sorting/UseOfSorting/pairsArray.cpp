#include<bits/stdc++.h>
using namespace std;

// Print the number of ordered pairs (i, j) such that i < j  and A[i] > A[j].

int counter=0;

void merge(int arr[],int beg,int mid,int end){

    int i=beg,j=mid+1;
    int temp[end-beg+1];
    int index=0;


    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp[index] = arr[i];
            i++;
        }else{
            temp[index]=arr[j];
            counter++;
            j++;
        }
        index++;
    }

    while(i<=mid){
        temp[index] =  arr[i];
        i++;
        index++;
        counter++;
    }

    while(j<=mid){
        temp[index] =  arr[j];
        j++;
        index++;
    }


    for(i=0;i<index;i++){
        arr[beg] = temp[i];
        beg++;
    }


}




void mergeSort(int arr[],int beg,int end){
    int mid;
    if(beg<end){
        mid = (beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }


}


void printArr(int arr[],int n){

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

int main(){

    int n=5;
    int arr[] = {4,5,3,1,2};

    mergeSort(arr,0,n-1);

    printArr(arr,n);

    cout<<counter<<endl;

}
