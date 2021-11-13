#include<bits/stdc++.h>
using namespace std;

int countSubarraysWithSameSumAndProduct(int arr[],int n){

    int ans = 0;
    for(int i=0;i<n;i++){
        int curr_sum = 0;
        int curr_prod = 1;
        for(int j=i;j<n;j++){
            curr_sum  += arr[j];
            curr_prod *= arr[j];
            if(curr_sum == curr_prod)
                ans++;
        }
    }
    return ans;
}

int main(){

    int arr[] = {4,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<countSubarraysWithSameSumAndProduct(arr,n)<<endl;

    return 0;
}


// O(n^2)