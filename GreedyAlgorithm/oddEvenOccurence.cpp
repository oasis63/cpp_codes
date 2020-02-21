#include<bits/stdc++.h>
using namespace std;

/*
    No working probperly 
*/

int main(){
    
    //int arr[] = {2,3,2,3,2};
    //int arr[] = {2,3,2,2,3,2,3,2,3};
    // int arr[] = {2,2,2,2,2,3,3,3,3};
    int arr[] = {2,2,3,2,3,2,3,2,3,2,3,3,2,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i=0,j=1;

    /*while(i<n && j<n){
        if(arr[j] == arr[i]){
            j++;
        }else{
            i++;
            j++;
        }
    }*/

    while(i<n && j<n){

        if(arr[j] != arr[i]){
            i++;
        }

        j++;
    }

    //cout<<i<<endl;
    cout<<"Number Occurs Odd number of Times : ";
    cout<<arr[i]<<endl;

    return 0;
}