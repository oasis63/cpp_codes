#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1000000007;
  
void multiply(ll F[2][2], ll M[2][2]) 
{ 
  ll x =  ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod; 
  ll y =  ((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod; 
  ll z =  ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod; 
  ll w =  ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 

void power(ll F[2][2], ll n) 
{ 
  ll i; 
  ll M[2][2] = {{1,1},{1,0}}; 
  
  for (i = 2; i <= n; i++) 
      multiply(F, M); 
}
  
ll fib(ll n,ll a,ll b) 
{ 
  ll F[2][2] = {{b,a},{a,b-a}}; 
  if (n == 0) 
      return 0; 
  power(F, n-1); 
  
  return F[0][0]; 
} 
   
  
/* Driver program to test above function */
int main() 
{ 
    ll tc;
    cin>>tc;

    while(tc--){
        ll a,b,n;    /* where a = first element   and    b = second element  */
        cin>>a>>b>>n;

        if(n==0)
          cout<<a<<endl;
        else if(n==1)
          cout<<b<<endl;
        else if(n==2)
          cout<<a+b<<endl;
        else
          cout<<fib(n+1,a,b)<<endl;
    }
} 