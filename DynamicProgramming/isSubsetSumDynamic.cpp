#include<bits/stdc++.h>
using namespace std;


bool isSubsetSum(int arr[],int n,int sum){

    if(sum==0)
        return true;
    if(n==0 && sum!=0)
        return false;
    if(arr[n-1] > sum)
        return isSubsetSum(arr,n-1,sum);

    //        exclude               ||    include the current element
    return  isSubsetSum(arr,n-1,sum) || isSubsetSum(arr,n-1,sum-arr[n-1]);
}


bool isSubsetSumDyna(int arr[],int n,int sum){

    int table[n+1][sum+1];

    //if sum is zero
    for(int i=0;i<=n;i++){
        table[i][0] = true;   // is possible sum
    }
    // it the number is zero
    for(int j=1;j<=sum;j++){
        table[0][j] = false;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<arr[i-1])
                table[i][j] = table[i-1][j];
            if(j>arr[i-1])
                table[i][j] = table[i-1][j] || table[i-1][j-arr[i-1]];
        }
    }

    return table[n][sum];
}


int main(){

    int arr[] = {3,34,4,12,5,2};
    int n = 6;
    int sum = 2;

    // cout<<isSubsetSum(arr,n,sum)<<endl;
    cout<<isSubsetSumDyna(arr,n,sum)<<endl;
}