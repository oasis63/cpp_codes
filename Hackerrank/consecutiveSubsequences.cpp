#include<bits/stdc++.h>
using namespace std;

/*
  Count consecutive subsequences whose sum is divisible by k  
*/

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
    
    ll tc;
    cin>>tc;

    while(tc--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];

        for(ll i=0;i<n;i++)
            cin>>arr[i];

        ll preSum[n];
        preSum[0] = arr[0];

        for(ll i=1;i<n;i++){
            preSum[i] = preSum[i-1]+arr[i];
        }

        ll counter[111];
        memset(counter,0,sizeof(counter));
        counter[0]=1;

        for(ll i=0;i<n;i++){
            counter[preSum[i]%k]++;
        }

        ll sum = 0;

        for(ll i=0;i<111;i++){
            sum += counter[i]*(counter[i]-1)/2;
        }

        cout<<sum<<endl;
    }



    return 0;
}

/*
Sample:

Input:

2
5 3
1 2 3 4 1
6 2
1 2 1 2 1 2


Output:

4
9


*/