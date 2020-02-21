#include<bits/stdc++.h>
using namespace std;


int minProductSubset(int arr[],int n){

    if(n==1)
        return arr[0];


    int count_neg = 0;
    int count_zeros=0;
    int min_pos = INT_MAX;
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

        if(arr[i] > 0){
            min_pos = min(min_pos,arr[i]);
        }


        prod = prod*arr[i];
    }


    if(count_zeros==n || (count_neg==0 && count_zeros > 0))
        return 0;

    if(count_neg==0)
        return min_pos;


    // if there are even number of negative numbers

    if(!(count_neg & 1) && count_neg!=0){
        prod = prod/max_neg;
    }

    return prod;
}



int main(){


    int a[] = { -1, -1, -2, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << minProductSubset(a, n);
    return 0;


}
