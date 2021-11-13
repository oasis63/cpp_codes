#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll fact[100005]={0};

ll modExp(ll x,ll n,ll m){
    if(n==0)
        return 1;
    else if( n%2 == 0)
        return modExp((x*x)%m,n/2,m);
    else
        return (x*modExp((x*x)%m,(n-1)/2,m))%m;
}


ll modInverse(ll A,ll M)
{
    return modExp(A,M-2,M);
}



int main(){
    fact[0]=1;
    for(int i=1;i<=100004;i++)
        fact[i] = (fact[i-1]*i)%mod;

    ll t,n,k,m,w,i;
    cin>>t;

    while(t--){
        cin>>n>>k>>m>>w;

        ll mf = fact[m];
        ll wf = fact[w];

        ll  ans=0;

        for(i=k;i<=n;i++){
           long long m1 = fact[m];
            long long m2 = (fact[i]*fact[m-i])%mod;
            long long m3 = (m1*modInverse(m2,mod))%mod;

            long long w1 = fact[w];
            long long w2 = (fact[n-i]*fact[w-(n-i)])%mod;
            long long w3 = (w1*modInverse(w2,mod))%mod;

            ans =  (ans+(m3*w3)%mod)%mod;
        }

        cout<<ans<<endl;
    }

}
