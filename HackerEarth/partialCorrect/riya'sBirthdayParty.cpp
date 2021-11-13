#include <bits/stdc++.h>
using namespace std;

#define ll long long unsigned int 

int main()
{
    int t;
    cin>>t;
    
    ll mod = 1e9 + 7;
    
    while( t-- )
    {
        ll n;
        cin>>n;
        
        ll ans = 2*n*n - n;
        
        ans = ans%mod;
        
        cout<<ans<<endl;
    }
}
