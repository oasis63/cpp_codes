#include <bits/stdc++.h>
using namespace std;

int  min(int  a[],int  n)
{
	int  m = a[0];
	
	for(int  i=0;i<n;i++)
	{
		if( a[i] < m)
			m=a[i];
	}

	return m;
}



int main()
{
	
	int  s,n,m;
	cin>>s>>n>>m;

	int  k[n],u[m];

	for(int  i=0;i<n;i++)
		cin>>k[i];
	for(int  i=0;i<m;i++)
		cin>>u[i];

	int  minPrice = min(k,n) + min(u,m);

	if( minPrice > s)
	{
		cout<<-1<<endl;
	}
	else
	{
		int  maxPrice=0;

		for(int  i=0;i<n;i++)
		{
			for(int  j=0;j<m;j++)
			{
				if( (k[i]+u[j]) > maxPrice && (k[i]+u[j]) <= s )
					maxPrice = (k[i]+u[j]);
			}
		}

		cout<<maxPrice<<endl;

	}

}