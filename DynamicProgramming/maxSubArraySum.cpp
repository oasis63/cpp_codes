#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[],int n){

    int max_so_far = arr[0];
    int max_current = arr[0];

    for(int i=1;i<n;i++){
        max_current = max(arr[i],max_current+arr[i]);
        max_so_far = max(max_so_far,max_current);
    }

    return max_so_far;
}



int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    cout << maxSubArraySum(a, n);
    return 0;
}
