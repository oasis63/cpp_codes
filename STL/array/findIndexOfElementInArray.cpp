#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int key ;
	cin>>key;

	// int x = distance(a,find(a,a+n,key));

	// cout<<x<<endl;
	int *p = find(a,a+n,key);

	int x = distance(a,p);    // x = distance(a,find(a,a+n,key));

	if( x != n)
		cout<<"yes"<<endl;
	else
		cout<<"No"<<endl;

	cout<<*p<<endl;

	cout<<"Index "<<x<<endl;

	return 0;
}