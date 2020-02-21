#include <bits/stdc++.h>
using namespace std;

//Array Vectors

int main ()
{
	vector<int> v[4];
	
	int count = 4;
	
	int size;
	cout<<"Enter the number of elements"<<endl;
	cin>>size;
	
	cout<<"Enter "<<size<<" Elements for "<<count<<endl;
	
	for (int i = 0; i < count; i += 1)
	{
		
		for (int  j = 0; j < size; j += 1)
		{
			int a;
			cin>>a;
			v[i].push_back(a);
		}
	}
	
	for (int i = 0; i < count; i += 1)
	{
	
		for (int j = 0; j < v[i].size(); j += 1)
		{
			cout<<v[i][j]<<" ";
		}
		
		cout<<endl;
	}
	
	return 0;
}


