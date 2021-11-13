#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);

    int t,n,k,i,temp,ans;cin>>t;

    priority_queue<int>pq;

    while(t--){

        cin>>n>>k;

        for(i=0;i<n;i++){
            cin>>temp;
            temp=__builtin_popcount(temp);
            pq.push(temp);
        }

        ans=0;

        for(i=0;i<k;i++){
            ans+=pq.top();pq.pop();
        }

        cout<<ans<<endl;

        pq=priority_queue<int>();
    }

}
