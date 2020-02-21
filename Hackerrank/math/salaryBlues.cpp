#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long


ll gcd(ll a,ll b){

    if(a==b)
        return a;

    if(b==0)
        return a;
    else
        return gcd(b,a%b);

}

int main(){
    ll n,q;
    cin>>n>>q;

    ll arr[n];
    bool sameValues = true;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i>0 && arr[i]!=arr[i-1]){
            sameValues = false;
        }
    }

    ll gd = 0;
    for(int i = 0;i<n;i++){
        gd = gcd(gd,arr[i]);
    }

    //cout<<gd<<endl;
    ll k;

    while(q--){
        cin>>k;

        if(sameValues){
            cout<<k+arr[0]<<endl;
        }else{
            cout<<gcd(k,gd)<<endl;
        }

    }
}
