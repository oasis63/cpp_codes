#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
	
    ll tc;
    cin>>tc;
    
    while(tc--){
        
        ll n,a,b;
    	cin>>n;
    
    	vector<ll> in;
    	vector<ll> out;
    
    	for(ll i=0;i<n;i++){
    		cin>>a>>b;
    		in.push_back(a);
    		out.push_back(b-1);   // since b is excluded 
    	}
    
    	sort(in.begin(),in.end());
    	sort(out.begin(),out.end());
    
    
    	ll sum=0;
    	ll mx=0;
    
    	ll i=0,j=0;
    
    	while(i<n && j<n){
    		if(in[i] <= out[j]){
    			sum++;
    			if(sum >= mx)
    				mx=sum;
    			i++;
    		}else{
    			sum--;
    			if(sum >= mx)
    				mx=sum;
    			j++;
    		}
    	}
    
    	cout<<mx<<endl;
    
    }

	return 0;
}