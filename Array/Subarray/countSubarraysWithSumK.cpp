#include<bits/stdc++.h>
using namespace std;

int countSubarraysWithSumK(int arr[],int n,int k){

    int ans = 0;
    for(int i=0;i<n;i++){
        int curr_sum = 0;
        for(int j=i;j<n;j++){
            curr_sum  += arr[j];
            if(curr_sum == k)
                ans++;
        }
    }
    return ans;
}

int main(){

    int arr[] = {9, 4, 20, 3, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 33;

    cout<<countSubarraysWithSumK(arr,n,k)<<endl;

    return 0;
}


// O(n^2)