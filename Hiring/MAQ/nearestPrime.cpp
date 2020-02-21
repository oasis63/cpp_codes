#include<bits/stdc++.h>
using namespace std;

int checkPrime(int n){

    if(n<2)
        return 0;
    if(n==2)
        return 1;

    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return 0;
    }

    return 1;
}

int nearestPrime(int n){


    int left=n-1;
    int right = n+1;


    while(1){
        if(checkPrime(left))
            break;
        left--;
    }

    while(1){
        if(checkPrime(right))
            break;
        right++;
    }

    int diff1 = abs(left - n);
    int diff2 = abs(right - n);

    if(diff1 <= diff2)
        return left;
    else
        return right;

}

int main(){

    int n;
    cin>>n;

    cout<<nearestPrime(n)<<endl;
}
