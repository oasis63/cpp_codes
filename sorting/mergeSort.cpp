// Divide and Conquer
#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int beg,int mid,int end){
    int i=beg,j=mid+1;
    int temp[end-beg+1];
    int index=0;

    while(i<=mid && j <= end){
        if(a[i] < a[j]){
            temp[index] = a[i];
            i++;
        }else{
            temp[index] = a[j];
            j++;
        }
        index++;
    }


    if(i>mid){
        while(j<=end){
            temp[index] = a[j];
            j++;
            index++;
        }

    }else{
        while(i<=mid){
            temp[index] = a[i];
            i++;
            index++;
        }
    }


    for(int k=0;k<index && beg<=end;k++){
        a[beg] = temp[k];
        beg++;
    }
}


// divide
void mergeSort(int a[],int beg,int end){    // T(n)
    int mid;
    if(beg<end){
        mid = (beg+end)/2;
        mergeSort(a,beg,mid);           //  T(n/2)
        mergeSort(a,mid+1,end);         // T(n/2)
        merge(a,beg,mid,end);           // O(n)
    }
}

// Time Complexity :-   nlog(n)

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int input[] = {3,0,3,2,1,0};
    int n=6;
    mergeSort(input,0,n-1);
    display(input,n);
}
