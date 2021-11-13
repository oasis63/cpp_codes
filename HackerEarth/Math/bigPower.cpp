#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define ull unsigned long long

// #define mod 1000000007

ll modExpo(ll x,ll n){

    if(n==0){
        return 1;
    }
    if(n%2==0){
        return modExpo((x*x)%1000000007,n/2)%1000000007;
    }else{
        return (x*modExpo((x*x)%1000000007,(n-1)/2))%1000000007;
    }
}

int main(){

    int tc;
    cin>>tc;
    ull x,y;
    while(tc-- >0){
        cin>>x>>y;
        x=x%1000000007;
        // y=y%1000000007;  // do not add this
        cout<<modExpo(x,y)%1000000007<<endl;
    }

    return 0;
}