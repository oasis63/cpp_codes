#include<bits/stdc++.h>
using namespace std;

// Fibonacci Numbers below K
void calcFibo(vector<int> fibo,int k){

    fibo.push_back(0);
    fibo.push_back(1);
    fibo.push_back(1);

    int i=3,nextTerm;

    while(1){
        nextTerm = fibo[i-1] + fibo[i-2];

        if(nextTerm > k)
            return;
        fibo.push_back(nextTerm);
        i++;
    }
}

int main(){

    int k=10;
    int arr[] = {1,2,4,-2,1,3,7};

    int n = sizeof(arr)/sizeof(arr[0]);

    int count=0;

    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            count++;
            k-=arr[i];
        }
    }

    cout<<count<<endl;

}
