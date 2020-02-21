

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
// scanning
#define sc1(x) scanf("%d",&(x))
#define sc2(x,y) scanf("%d%d",&(x),&(y))
#define scl(x) scanf("%lld",&(x))
#define scl2(x,y) scanf("%lld%lld",&(x),&(y))
 
// loops
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
 
// printing
#define pf1(x) printf("%d\n",(x))
#define pf2(x,y) printf("%d %d\n",(x),(y))
#define pfl(x) printf("%lld\n",(x))
#define pfl2(x,y) printf("%lld %lld\n",x,y)
#define pfc(x) printf("%c\n",(x))
#define pn() printf("\n");
 
// utilities
#define vi vector<int>
#define vii vector<vi> 
#define pb push_back 
#define map map<int, int> 
#define pr pair<int, int>
#define mk make_pair
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
 
// declarations
const int mod = 1e9+7;
const int mxm = 1e5+1;
const int MXM = 1e8+1;
 
int q[241];
int p[1000001];
 
ll power(ll a, ll b)
{
    if(b==0)
        return 1;
    else if(b==1) return a;
    else
    {
        ll c=power(a,b/2);
        c=(c*c);
        if(c>mod)
            c%=mod;
        if(b%2==0)
        return c;
        else return (c*a)>mod?(c*a)%mod:(c*a);
    } 
}
 
int main()
{
    int t,n,i,j;
    sc1(t);
    sc1(n);
    for(i=1;i<=n;i++)
    { 
        for(j=1;j<=n/i;j++) 
            p[i*j]++;
    }
    for(i=1;i<=n;i++) 
        q[p[i]]++;
    for(i=2;i<=240;i++)
        q[i]=q[i]+q[i-1];
    while(t--)
    {
        sc1(n);
        pf1(q[p[n]-1]);
    }
    return 0;
}

