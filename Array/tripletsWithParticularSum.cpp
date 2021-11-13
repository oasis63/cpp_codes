// A Simple C++ program to count triplets with sum smaller
// than a given value
#include<bits/stdc++.h>
using namespace std;

int countTriplets(long long arr[], int n, long long  sum)
{
    // Initialize result
    int ans = 0;

    sort(arr,arr+n);

    // Fix the first element as A[i]
    for (int i = 0; i < n-2; i++)
    {
       // Fix the second element as A[j]
       for (int j = i+1; j < n-1; j++)
       {
           // Now look for the third number
           for (int k = j+1; k < n; k++)
               if (arr[i] + arr[j] + arr[k] > sum)
                   ans++;
       }
    }

    return ans;
}

// Driver program
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        long long  a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        long long  lim; cin>>lim;

        cout<<countTriplets(a,n,lim)<<endl;
    }
}
