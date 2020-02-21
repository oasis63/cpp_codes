#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
	
	ll n,m;
	cin>>n>>m;

	ll tasks[m];
	for(ll i=0;i<m;i++){
		cin>>tasks[i];
	}

	ll curr = 1;
	ll steps = 0;

	for(ll i=0;i<m;i++){

		if(tasks[i] > curr){
			steps += (tasks[i]-curr);
			curr = tasks[i];
		}else if(tasks[i] < curr){
				steps += n-curr+1;
				curr=1;

				steps += (tasks[i]-curr);
				curr = tasks[i];
		}
	}	

	cout<<steps<<endl;

	return 0;
}