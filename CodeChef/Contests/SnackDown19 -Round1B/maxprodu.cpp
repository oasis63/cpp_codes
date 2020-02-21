#include<iostream>
using namespace std;
typedef long long int ll;


ll cal(ll a,ll k)
{
	ll i,ans=1,sampart=1,m=7+1e+9;
	for(i=a;i<=a+k-2;++i)
	{
		sampart*=i;
		if(sampart>m)
		{
			sampart=sampart%m;
			ans=(ans*sampart)%m;
			sampart=1;
		}
		else if(sampart==m)
		{
			ans=0;
			break;
		}
	}



	ans=(ans*sampart)%m;
	ans=(ans*ans)%m;
	ans=(ans*(a-1))%m;
	ans=(ans*(a+k-1))%m;
	return ans;
}
int main()
{
	int qq;
	cin>>qq;


	while(qq--)
	{
		ll mn,k,a,ra,l,ans,m=7+1e+9;
		cin>>mn>>k;
		if(k*(k+1)>2*mn)
			cout<<"-1"<<endl;
		else if (k*(k+1)==2*mn)
			cout<<"0"<<endl;
		else
		{
			l=mn-(k*k+k)/2;
			for(ra=k;ra>0;)
			{
				if((ra+l)%k==0)
				{
					a=(ra+l)/k;
					break;
				}
				--ra;
			}
			if(ra==k)
				cout<<cal(a,k)<<endl;


			else
			{
				ans=(cal(a,ra)*cal(a+ra+1,k-ra))%m;


				cout<<ans<<endl;
			}
		}
	}
}
