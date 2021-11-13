#include <bits/stdc++.h>
using namespace std;

int prime(int n)
{
	int s = sqrt(n);


	if(n == 1)
		return 0;

	for (int i = 2; i <= s ; ++i)
	{
		/* code */

		if(n%i==0)
			return 0;
	}

	return 1;
}


int diffDiv(int n)
{
	int dCount = 0;
	int pCount = 0;

	for(int i = 1 ; i <= n ; i++)
	{
		if(n % i == 0)
		{
			dCount ++ ;

			if(prime(i))
				pCount ++;
		}
	}

	return (dCount - pCount);
}



int main()
{
	vector <int> v;

	int l,r;
	cin>>l>>r;

	int big = 0;

	for(int i = l ; i < r ; i++)
	{
		int res = diffDiv(i);

		if( res > big)
		{
			big = res;
			v.push_back(i);

		}

		else if( res == big)
		{
			int last = v.back();

			if( i > last)
			{
				v.push_back(i);
			}
		}
	}

	cout<<v.back()<<endl;

	return 0;
}