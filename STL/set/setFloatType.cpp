#include <bits/stdc++.h>
using namespace  std;

// repetition is not allowed in set 

int main()
{
	set<float> mySet;

	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		float temp;
		cin>>temp;
		mySet.insert(temp);
	}

	set<float>:: iterator itr = mySet.begin();

	while( itr != mySet.end())
	{
		cout<<*itr<<" ";
		itr ++;
	}

	return 0;
}
