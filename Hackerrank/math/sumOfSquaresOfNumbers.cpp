#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll  long long

void solve(ll n ){


        
    ll sq = cbrt(3*n);
    ll prev=n;

    while(sq > 0){

       ll cal = (sq*(sq+1)*(2*sq+1))/6;

        if(cal == n){
            cout<<sq<<endl;
            break;
        }else if(cal < n && prev >= n){
            cout<<sq<<endl;
            break;
        }

        prev = cal;
        sq--;
    }


    return;
}

int main(){

    fast;

    int tc;
    cin>>tc;
    ll n;
    while(tc--){
        cin>>n;
        solve(n);
    }
}
