#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a,ll b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

ll gcdArr(ll arr[],ll n){
    ll result=arr[0];  // let it be the LCM

    for(ll i=1;i<n;i++){
         result= ( ((arr[i]*result)) / (gcd(arr[i], result)) );
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll tc;cin>>tc;
    while(tc--){
        ll n;cin>>n;
        ll num[n];
        for(ll i=0;i<n;i++)
            cin>>num[i];
        cout<<gcdArr(num,n)<<endl;
    }

}
