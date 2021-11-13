#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long int


ll solve(ll n){

    ll ans = 0;

    if(n==1)
        return -1;
    else if(n==2 || n==3 || n==5 || n==7)
        return 1;


    if(n/7!=0){ // n is less than 7
        ans += n/7;
        n=n%7;
        if(n==0 || n==1)
            return ans+n;
    }

    if(n/5!=0){   // n is less than 5
        ans += n/5;
        n=n%5;
        if(n==0 || n==1)
            return ans+n;
    }

    if(n/3!=0){  // n is less than 3
        ans += n/3;
        n=n%3;
        if(n==0 || n==1)
            return ans+n;
    }

    if(n/2!=0){   // n is less than 2
        ans += n/2;
        n=n%2;
        if(n==0 || n==1)
            return ans+n;
    }


    return -1;
}

int main(){

    ll tc;cin>>tc;

    while(tc--){
        ll n,k;cin>>n;
        cout<<solve(n)<<endl;

    }

    return 0;
}
