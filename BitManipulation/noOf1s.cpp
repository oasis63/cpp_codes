#include <bits/stdc++.h>
using namespace std;

// userdefined function for counting the number of 1s bits
int can(int n)
{
	int count = 0;
	while(n!=0)
	{
		n=n&(n-1);   // if n is a power of 2 then n&(n-1) will become 0
		count ++;
	}

	return count;
}

int main()
{
	int n;
	cout<<"Enter a number to count the number 1s in its binary number"<<endl;
	cin>>n;
	int res = __builtin_popcountll(n);

	cout<<res<<endl;
}

/*
	__builtin_popcountll(n)     // predefined function for counting the number of 1s

	there are two underscore   __
*/

