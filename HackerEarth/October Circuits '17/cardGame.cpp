#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ll n,m,temp;
        cin>>n;
        ll fp[n];
        for(ll i=0;i<n;i++)
            cin>>fp[i];

        cin>>m;
        priority_queue<int> pq;
        for(ll i=0;i<m;i++){
            cin>>temp;
            pq.push(temp);
        }

        ll mx=pq.top();pq.pop();

        mx++;

        ll ans=0;

        for(ll i=0;i<n;i++){
            if(mx > fp[i]){
                ans+=abs(mx-fp[i]);
            }
        }


        cout<<ans<<endl;

        pq=priority_queue<int>();



}
