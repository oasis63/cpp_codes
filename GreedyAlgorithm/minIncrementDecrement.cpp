#include<bits/stdc++.h>
using namespace std;


/*
Minimum increment/decrement to make array non-Increasing
*/


int decreasingArray(int arr[],int n){

    priority_queue<int,vector<int>,greater<int>> pq;

    int sum = 0;

    for(int i=0;i<n;i++){

        if(!pq.empty() && arr[i] > pq.top()){
            int top_elem = pq.top();
            int diff =  arr[i] - top_elem;
            sum += diff;
            pq.pop();
            pq.push(top_elem);
        }else
            pq.push(arr[i]);
    }

    return sum;
}

int main(){

    int arr[] = {3,1,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<decreasingArray(arr,n)<<endl;
}
