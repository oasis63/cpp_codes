// Double pointer

#include<bits/stdc++.h>
using namespace std;

int main(){
    // find the sum in the given sorted array

    int a[] = {4,5,6,7,8};
    int sum=10;
    int n=5;

    int l=0,r=n-1;

    while(l<r){
        if(a[l]+a[r]==sum){
            cout<<l<<" "<<r<<endl;
            break;
        }
        else if(a[l] + a[r] > sum){
            r--;
        }
        else
            l++;
    }


}
