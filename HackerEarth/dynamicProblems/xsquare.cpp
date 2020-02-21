#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    ll n,q;
    cin>>n>>q;

    ll a[n];
    ll b[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<n;i++)
        cin>>b[i];

    ll t,st,ed,sum=0;

    while(q--){
        cin>>t>>st>>ed;
        sum=0;
        if(t==1){
            ll tokA=1;
            for(ll i=st-1;i<ed && i<ed;i++){
                if(tokA){
                    sum += a[i];
                    tokA=0;
                }else{
                    sum += b[i];
                    tokA=1;
                }
            }

        }else{

            ll tokB=1;
            for(ll i=st-1;i<ed && i<ed;i++){
                if(tokB){
                    sum += b[i];
                    tokB=0;
                }else{
                    sum += a[i];
                    tokB=1;
                }
            }
        }

        cout<<sum<<endl;
    }

}
