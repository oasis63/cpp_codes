#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<list>
#include<math.h>
#include<ctime>
#define LL long long
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define FOR(i,lb,ub) for(i=lb;i<=ub;i++)
#define RFOR(i,ub,lb) for(i=ub;i>=lb;i--)
#define FORS(it,v) for(it=v.begin();it!=v.end();it++)
#define st_clk double st=clock();
#define end_clk double en=clock();
#define show_time cout<<"\tTIME="<<(en-st)/CLOCKS_PER_SEC<<endl;
#define sc(n) scanf("%d",&n)
#define scst(n) scanf("%s",n)
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
LL gcd(LL a, LL b) { return b?gcd(b,a%b):a; }
using namespace std;
 #ifndef ONLINE_JUDGE
inline int getchar_unlocked() { return getchar(); }
#endif
template <class T>
inline void r_f(T &p)
{
         char c;
         int neg=0;
         while ((c=getchar_unlocked()) < 48 || c > 57)
		 	if (c==45)
		 		neg=1;
         p=c-48;
         while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
         if (neg) p*=-1;
}
int main()
{
     #ifndef ONLINE_JUDGE
     f_in("in.txt");
     //f_out("out.txt");
     #endif
     int n,ar[55],ks,key_ar[1005],key_sum=0,i;
     cin>>n;
     assert(n<=50);
     FOR(i,0,n-1)
     {
     	cin>>ar[i];
     	assert(ar[i]<=1000);
     }
     sort(ar,ar+n);
     cin>>ks;
     assert(ks<=50);
     FOR(i,0,ks-1)
     {
     	cin>>key_ar[i];
     	assert(key_ar[i]<=50);
     	key_sum += key_ar[i];
     }
     sort(key_ar,key_ar+ks);
     if (key_sum<n)
     {
     	cout<<-1;
     	return 0;
     }
     int ans=0,indx=1,j;
     for (i=n-1;i>=0;)
     {
     	for (j=0;j<ks && i>=0;j++)
     	{
     		if (key_ar[j]>0)
     		{
     			key_ar[j]--;
     			ans += indx*ar[i];
     			i--;
     		}
     	}
     	indx++;
     }
     cout<<ans;
     
return 0;