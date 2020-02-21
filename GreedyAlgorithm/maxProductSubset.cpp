#include<bits/stdc++.h>
using namespace std;


int maxProductSubset(int arr[],int n){

    if(n==1)
        return arr[0];


    int count_neg = 0;
    int count_zeros=0;
    int max_neg = INT_MIN;
    int prod = 1;

    for(int i=0;i<n;i++){

        if(arr[i]==0){
            count_zeros++;
            continue;
        }

        if(arr[i] < 0){
            count_neg++;
            max_neg = max(max_neg,arr[i]);
        }

        prod = prod*arr[i];
    }


    if(count_zeros==n)
        return 0;


    // if there are odd number of negative numbers

    if(count_neg&1){

        if(count_neg == 1 && count_zeros > 0 && count_zeros+count_neg == n)
            return 0;

        prod = prod/max_neg;
    }

    return prod;
}



int main(){


    int a[] = { -1, -1, -2, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;


}
