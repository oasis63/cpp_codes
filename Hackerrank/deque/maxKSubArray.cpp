#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll  long long

void printMaxOfSubArr(ll arr[],ll n,ll k){

  
    deque<ll> dq(k);

    ll i=0;

    for(i=0;i<k;++i){

        // remove the smaller elements from the back of the queue
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    for(;i<n;++i){
        cout<<arr[dq.front()]<<" ";

        // remove the front elements which are out of the interval
        while(!dq.empty() && dq.front() <= i-k )
            dq.pop_front();

        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    cout<<arr[dq.front()]<<endl;
}


int main(){
    fast;
    
    int tc;
    cin>>tc;
    ll n,k;
    while(tc--){
        cin>>n>>k;
        ll arr[n];

        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }

        printMaxOfSubArr(arr,n,k);

    }

}
