#include <iostream>
using namespace std;
#define mod 1000000007

long long fact[100005]={0};
long long mode(long long a,long long n,long long m){
    long long res = 1;
    while(n){
    if(n%2) res = (res*a)%m;
    
    a = (a*a)%m;
    n /= 2;
    }
    return res; 
}
int main()
{   
    fact[0]=1;
    for(int i=1;i<=100004;i++) 
        fact[i] = (fact[i-1]*i)%mod;

    long long t,n,m,k,w,i;
    cin>>t;
    
    while(t--){
        cin>>n>>k>>m>>w;
        long long ans = 0;
        for(i=k;(i<=m && i<=n);i++){
            long long m1 = fact[m];
            long long m2 = (fact[i]*fact[m-i])%mod;
            long long m3 = (m1*mode(m2,mod-2,mod))%mod;
            
            long long w1 = fact[w];
            long long w2 = (fact[n-i]*fact[w-(n-i)])%mod;
            long long w3 = (w1*mode(w2,mod-2,mod))%mod;
            
            ans =  (ans+(m3*w3)%mod)%mod;
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}