#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll maxIsoVert(ll n,ll m){

	if(m==0)
		return n;

	ll ans = 0;

	ll temp = (n*(n-1))/2; 

	for(ll i=n-1;i>=1;i--){
		ll temp2 = (i*(i-1))/2;
		if(temp2 < m  && temp >= m){
			ans = i+1;
			break;
		}else{
			temp=temp2;
		}
	}

	return (n-ans);
}


int main(){
	
	ll n,m;
	cin>>n>>m;

	ll mn=0,mx=0;

	ll temp = m*2;

	if(temp >= n){
		mn=0;
	}else{
		mn = n - temp;
	}


	mx = maxIsoVert(n,m);


	cout<<mn<<" "<<mx<<endl;


	return 0;
}