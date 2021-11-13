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

	int x = distance(a,find(a,a+n,key));   // returns the index of the key in the array

	cout<<x<<endl;

	return 0;
}