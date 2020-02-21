#include<bits/stdc++.h>
using namespace std;

// recursive binomial cofficient

int binomialCoeff(int n,int r){

    //base case
    if(r==0 || n==r)
        return 1;

    // recur
    return binomialCoeff(n-1,r)+binomialCoeff(n-1,r-1);
}

int main(){

    cout<<binomialCoeff(4,2)<<endl;
}
