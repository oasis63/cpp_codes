#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define mxCount 100005

int a[mxCount];


int main(){

    ll n;cin>>n;

    for(ll i=0;i<n;i++)
            cin>>a[i];

    sort(a,a+n);

    ld logSum=0;  // logY ..-<<  x^n > y => nlogX >

    for(ll i=0;i<n;i++){

        logSum += (ld)log((ld)a[i]);  //

    }

    //cout<<logSum<<endl;

    ll left=a[0],right=a[n-1]+1,ans;

    while(left<=right){

        ll mid=(left+right)/2;
        ld temp = (ld)n*(ld)log((ld)mid);

        if( temp > logSum){
            ans=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }

    cout<<ans<<endl;
    return 0;

}
