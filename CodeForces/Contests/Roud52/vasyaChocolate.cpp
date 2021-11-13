#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
	
	ll tc;
	cin>>tc;

	ll s,a,b,c,count;

	while(tc--){
		cin>>s>>a>>b>>c;

		ll count = s/c;
		ll div = count/a;
		count += div*b;

		cout<<count<<endl;

	}

	return 0;
}