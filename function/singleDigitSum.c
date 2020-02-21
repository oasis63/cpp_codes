#include <bits/stdc++.h>
using namespace std;

#define ll long long unsigned int

ll sumDigit(ll n)
{
	if( n%9 ==0 )
	{
		return 9;
	}
	else if( n>9 && n%9!=0)
	{
		return n%9;
	}
	else
	{
		return n;
	}

}

int main()
{
	ll   n;
	cout<<"\nEnter a number"<<endl;
	cin>>n;

	cout<<sumDigit(n)<<endl;

}
