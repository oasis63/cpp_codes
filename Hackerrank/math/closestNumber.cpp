#include<bits/stdc++.h>
using namespace std;

#define ll  unsigned long long


int main(){


    ll tc;
    cin>>tc;

    while(tc--){
        ll a,b,x;
        cin>>a>>b>>x;

        ll d = pow(a,b)+x/2;
        d=d-(d%x);

        cout<<d<<endl;
    }

}
