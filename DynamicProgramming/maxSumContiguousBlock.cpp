#include<bits/stdc++.h>
using namespace std;

// DP

int maxContSum(int a[],int n){
    int m[n]={0},maxSum=0;

    if(a[0] > 0)
        m[0]=a[0];
    else
        m[0]=0;

    for(int i=1;i<n;i++){

        if((m[i-1]+a[i]) > 0)
            m[i]=m[i-1]+a[i];
        else
            m[i]=0;
    }

    for(int i=0;i<n;i++){
        if(m[i] > maxSum)
            maxSum=m[i];
    }
    return maxSum;
}



int main(){

    int a[]={1,-3,4,-2,-1,6};

    cout<<maxContSum(a,6)<<endl;

}
