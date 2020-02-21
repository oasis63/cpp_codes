#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long


ll modExpo(ll x,ll n,ll M){

    ll ans = 1;

    while(n>0){
        if(n&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        n=n/2;
    }

    return ans%10;
}


int main(){

   int tc;
   cin>>tc;

   while(tc--){
        ll a,b;
        cin>>a;
        assert(a>=0 && a<=20);
        cin>>b;
        assert(b>=0 && b<= 2147483000);

        cout<<modExpo(a,b,10)<<endl;
   }
    
    

    return 0;
}