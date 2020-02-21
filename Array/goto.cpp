#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {10,20,30};
    int n = 3;
    int i=-1;
    int sum = 0;
    label:
        sum += arr[++i];

    // cout<<sum<<endl;

    if(i<n-1)
        goto label;

    cout<<sum<<endl;


}
