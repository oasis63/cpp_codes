#include<bits/stdc++.h>
using namespace std;

int countSubarraysWithGCD1(int *arr,int n){

    int ans = 0;

    for(int i=0;i<n;i++){
        int curr_gcd = 0;
        for(int j=i;j<n;j++){
            curr_gcd = __gcd(curr_gcd,arr[j]);
            ans += (curr_gcd == 1);
        }
    }
    
    return ans;
}


int main(){
    
    int arr[] = {1,1,1};
    int n = 3;

    // int arr[] = {2, 4, 6, 8, 16};
    // int n = sizeof(arr)/sizeof(arr[0]);

    cout<<countSubarraysWithGCD1(arr,n)<<endl;

    return 0;
}