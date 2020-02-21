#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int  main()
{
	int N = 5e5+1;
	int Q = 5e5+1;

	ll  n;
	cin>>n;

	n=n%N;

	vector<ll>num;

	for(ll  i=0;i<n;i++)
    {
    	ll temp;
    	cin>>temp;

    	num.push_back(temp);
    }

	ll  q;
	cin>>q;

	q = q%Q;

	//ll  query[q];

	// for(ll  i=0;i<q;i++)
	// 	cin>>query[i];

	for(ll  i=0;i<q;i++)
	{
		ll que;
		cin>>que;

		ll  sum=0;

		for(ll  j=0;j<n;j++)
		{
			num[j] += que;

			sum += abs(num[j]);
		}

		cout<<sum<<endl;
	}

}