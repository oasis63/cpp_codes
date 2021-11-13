#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[],int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

}

void nextGreatest(int arr[],int n){

    int right_greatest = arr[n-1];
    arr[n-1] = -1;

    for(int i=n-2;i>=0;i--){
        int temp = arr[i];
        arr[i] = right_greatest;

        if(temp > right_greatest)
            right_greatest=temp;
    }


}



int main(){
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextGreatest(arr, n);
    printArr(arr,n);
}
