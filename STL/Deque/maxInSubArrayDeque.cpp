//Maximum of all subarrays of size k

#include<bits/stdc++.h>
using namespace std;

void printMaxOfSubArr(int arr[],int n,int k){

    // to store the indexes of the maximum element
    // in the given range .. here it is k
    deque<int> dq(k);

    int i=0;

    for(i=0;i<k;++i){

        // remove the smaller elements from the back of the queue
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    for(;i<n;++i){
        cout<<arr[dq.front()]<<" ";

        // remove the front elements which are out of the interval
        while(!dq.empty() && dq.front() <= i-k )
            dq.pop_front();

        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    cout<<arr[dq.front()]<<endl;
}


int main(){

    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = 7;
    int k = 3;

    printMaxOfSubArr(arr,n,k);
}
