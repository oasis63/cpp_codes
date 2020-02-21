#include <bits/stdc++.h>
using namespace std;

int main()
{

	int n;
	cin>>n;

	int v[n];

	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}

	sort(v.begin(),v.end());

	int gcd = v[0];

	while(1)
	{
		int count = 0;

		for(int i=0;i<n;i++)
		{
			if( v[i]%gcd == 0)
				count ++;
		}

		if( count == n)
			break;
		else
			gcd --;
	}


	cout<<"\nGCD = "<<gcd<<endl;

	
}
