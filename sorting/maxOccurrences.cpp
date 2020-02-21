#include<bits/stdc++.h>
using namespace std;

#define ll long long

int func(int arr[],int n){

    sort(arr,arr+n);

    int mxCandidate=arr[0],currCandidate=arr[0];
    int mxCounter=1,currCounter=1;

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    for(int i=1;i<n;i++){

        if(arr[i] == currCandidate){
            currCounter++;
        }else{
            currCounter=1;
            currCandidate=arr[i];
        }

        if(currCounter > mxCounter){
            mxCounter = currCounter;
            mxCandidate = currCandidate;
        }
    }

    cout<<mxCandidate<<" "<<mxCounter<<endl;
}

int main(){

    int arr[] = {1,2,5,5,4,2,5,1,1,1,2,2,5,3,5,2,1,1,3,0,4,5,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    func(arr,n);

}
