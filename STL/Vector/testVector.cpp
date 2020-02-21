#include <bits/stdc++.h>
using namespace std;

//Array Vectors

int main ()
{
	vector<int> v[4];
	
	int count;
	
	cout<<"\nEnter the number of vectors"<<endl;
	cin>>count;
	
	int size;
	cout<<"Enter the number of elements"<<endl;
	cin>>size;
	
	cout<<"Enter "<<size<<" Elements for each of "<<count<<" vectors"<<endl;
	
	for (int i = 0; i < count; i += 1)
	{
		
		for (int  j = 0; j < size; j += 1)
		{
			int a;
			cin>>a;
			v[i].push_back(a);
		}
	}
	
	cout<<endl;
	
	for (int i = 0; i < count; i += 1)
	{
		vector<int>::iterator itr = v[i].begin();
		
		while( itr < v[i].end())
		{
			cout<<*itr<<" "<<endl;
			itr ++;
		}
		cout<<endl;
	}
	
	return 0;
}


