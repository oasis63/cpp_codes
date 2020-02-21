#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll modExpo(ll x,ll n,ll M){

    ll ans = 1;

    while(n>0){
        if(n&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        n=n/2;
    }

    return ans;
}

ll solve(ll n,ll m){

    if(n<6){
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        else if(n==2)
            return 11%m;
        else if(n==3)
            return 111%m;
        else if(n==4)
            return 1111%m;
        else if(n==5)
            return 11111%m;
    }

    if(n%2==0){

        ll temp = solve(n/2,m)%m;
        ll ans = (modExpo(10,n/2,m)*temp + temp)%m;
        return ans;

    }else{

        ll temp = solve(n/2,m)%m;
        ll ans = (modExpo(10,(n/2)+1,m)*temp + temp*10+1)%m;
        return ans;
    }


}

int main(){

    int tc;
    cin>>tc;
    ll n,m;

    while(tc--){
        cin>>n>>m;

        cout<<solve(n,m)<<endl;
    }
    
    

    return 0;
}