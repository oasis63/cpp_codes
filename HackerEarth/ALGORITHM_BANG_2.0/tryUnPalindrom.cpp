#include <bits/stdc++.h>
using namespace  std;

#define LEN 1000

/* Repetition of elements not allowed in set */

int reverse(int n)
{
	int rev=0;
	int i=10;
	while( n!=0)
	{
		int rem = n%10;

		rev = rev*10 + rem;

		n /= 10;
	}

	 return rev;
}

bool isPalindrome(int n)
{
	return reverse(n) == n;
}

int gcd(int x,int y)
{
	int r;
	while( y!= 0)
	{
		r = x%y;
		x=y;
		y=r;
	}

	return x;
}

int main()
{
	int n;
	cout<<"\nEnter the position of the non-palindromic Number\n"<<endl;
	cin>>n;

	/*map<int,int>m; int index=1; for(int i=1;i<=LEN;i++) {if( !isPalindrome(i)) {m[index] = i; index ++; } } cout<<m[n]<<endl;*/

	if( n== 1)
	{
		cout<<10<<endl;
	}
	else
	{
		if( n>= 2 && n<=11)
		{
			cout<<(n+10);
		}
		else if( n>= 12 && n<= 21)
		{
			cout<<(n+11);
		}
		else if( n>=22 && n<= 31)
		{
			cout<<(n+12);
		}
		else if( n >= 32 && n <= )











	}
}