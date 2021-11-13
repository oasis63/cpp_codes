#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"\nEnter a number"<<endl;
	cin>>n;


	if( n%9 ==0 )
	{
		cout<<9<<endl;
	}
	else if( n>9 && n%9!=0)
	{
		cout<<(n%9)<<endl;
	}
	else
	{
		cout<<n<<endl;
	}

}
