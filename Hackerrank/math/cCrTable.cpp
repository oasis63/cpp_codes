#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
const ll mod = 1000000000;

ll choose[1000][1000]={0};

void combination(ll n){

    for(ll j=0;j<=n;j++){
        choose[j][0]=1;
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=i;j++){
            choose[i][j]=(choose[i-1][j-1]+choose[i-1][j])%mod;
        }
    }
}

int main(){

    combination(999);

    ll tc,n;
    cin>>tc;


    while(tc--){
        cin>>n;
        for(ll j=0;j<=n;j++){
            cout<<choose[n][j]<<" ";
        }
        cout<<endl;
    }
}

