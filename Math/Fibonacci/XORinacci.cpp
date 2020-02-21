#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
    
    int tc;
    ll n,a,b;
    cin>>tc;

    while(tc--){
        cin>>a>>b>>n;
        ll c = a^b;
        ll r = n%3;

        if(r==0)
            cout<<a<<endl;
        else if(r==1)
            cout<<b<<endl;
        else
            cout<<c<<endl;
    }


    return 0;
}
