#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
	ll tc;cin>>tc;
	while(tc--){
	    ll ans = 0,temp;
	    ll n,k;cin>>k>>n;
	    for(ll i=0;i<n;i++){
	        cin>>temp;
	        if(temp < k){
	            ans += abs(temp-k);
	        }else{
	            ll t = temp%k;;
	            ans += min(t,k-t);
	        }
	    }
	    cout<<ans<<endl;
	}
	
	return 0;
}