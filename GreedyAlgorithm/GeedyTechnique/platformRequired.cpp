#include <bits/stdc++.h>
using namespace std;

/*
    Minimum Number of Platforms Required for a Railway/Bus Station
*/


int findPlatform(int arr[],int dep[],int n){

    sort(arr,arr+n);    // sort arrival times in increasing order
    sort(dep,dep+n);    // sort departure times in non-decreasing order

    int ans=0;
    int platform_needed=0;

    int i=0;
    int j=0;


    while(i<n && j<n){

        if(arr[i] <= dep[j]){

            platform_needed++;
            i++;

            if(platform_needed >= ans)
                ans = platform_needed;

        }else{
            
            platform_needed--;

             if(platform_needed >= ans)
                ans = platform_needed;

            j++;

        }
    }


    return ans;

}


int main(){
    
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = " << findPlatform(arr, dep, n);
    return 0;
}