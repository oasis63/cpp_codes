#include <bits/stdc++.h>
using namespace std;

// Think smart simple logic

#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,i;cin>>n;
    ll input[n];

    for(i=0;i<n;i++){
        cin>>input[i];
    }



    for(int i=1;i<n;i++){
        input[i-1] = input[i-1]^input[i];
    }

    ll ans=input[0];

    for(int i=1;i<n;i++){
        ans = ans|input[i];
    }

    cout<<ans<<endl;



}
