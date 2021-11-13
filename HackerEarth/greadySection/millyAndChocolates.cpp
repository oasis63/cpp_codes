#include<bits/stdc++.h>
using namespace std;

#define ll  long int

int main() {


	ll tc;cin>>tc;

	while(tc--){
	    ll n,k,m,t;
        cin>>n>>k>>m;

        ll choco[n];

        for(ll i=0;i<n;i++){
            cin>>choco[i];
        }


        ll index = -1;
        ll min_time = -1;

        ll turnTime  = k+m;

        for(ll i=0;i<n;i++){

            ll pieces = choco[i];
            ll temp_time = turnTime*pieces - m;

            for(ll j=0;j<pieces;j++){
                cin>>t;
                temp_time += t;
            }

            if(min_time == -1){
                min_time = temp_time;
                index=i+1;
            }else if(temp_time < min_time){
                min_time = temp_time;
                index = i+1;
            }
        }

        cout<<index<<" "<<min_time<<endl;
	}

	return 0;
}
