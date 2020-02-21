#include <bits/stdc++.h>
using namespace  std;

/* Repetition of elements not allowed in set */

int main()
{
	/*set<int> s; int n; cout<<"\nEnter the number of elements\n"<<endl; cin>>n; for (int i = 0; i < n; ++i) {int x; cin>>x; s.insert(x); } cout<<s.size()<<endl; set<int>::iterator itr = s.begin(); while( itr != s.end()) {cout<<*itr<<" "; itr ++; } return 0;*/ 

	int n,m;     
	cin>>n>>m;

	int x1,x2;
	cin>>x1>>x2;

	int setA[m];    // when n == 2 
	int setB[m];

	for (int i = 0; i < m; ++i)
	{
		setA[i] = x1;
		setB[i] = x2;

		x1 ++;
		x2 ++;
	}

	int size = m*(x1 + x2);

	int hash[size] = {0};

	for (int i = 0; i < m; ++i)
	{
		for (int i = 0; i < m; ++i)
		{
			hash[setA[i] + setB[i]] ++;
		}
	}

	int sum = 0;

	for (int i = 0; i < size; ++i)
	{
		sum += i*hash[i];
	}

	cout<<sum/9<<endl;



}