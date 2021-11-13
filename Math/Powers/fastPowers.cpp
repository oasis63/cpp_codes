#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long 

ll fast_pow(ll a,ll b){
    
    ll res = 1;

    while(b>0){
        if(b&1)
            res = (res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }

    return res;
}

int main(){
    
   cout<<fast_pow(4,4)<<endl;
   

    return 0;
}