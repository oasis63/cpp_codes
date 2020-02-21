#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define SIZE   10000001
#define SIZE2  100000001

bool checkPrime(ll n){
    if(n<=1)
        return false;
    if(n==2 || n==3)
        return true;

    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    }

    return true;

}



int main(){
    

    for(ll i=SIZE;i<SIZE+50;i++){
        cout<<i<<" "<<checkPrime(i)<<endl;
    }


    

}