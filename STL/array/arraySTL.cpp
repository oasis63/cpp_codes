#include <bits/stdc++.h>
using namespace std;

/*
Declaration of Class array may look like:

Template<class type,class size>
class array
{

};

It is  an implementation of the static array

example Objec:
array<int,5> obj;
*/

int main()
{
	array<int,5> arr;
	array<int,5>arr2;

	int n=5;

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	for(int i=0;i<n;i++)
	{
		cout<<arr.at(i)<<" ";
	}

	cout<<"\nFront Element: "<<arr.front()<<endl;
	cout<<"\nBack Element: "<<arr.back()<<endl;
	cout<<"\nSize :"<<arr.size()<<endl;

	arr2.swap(arr);   // swap of elements from arr to arr2

	for(int i=0;i<n;i++)
	{
		cout<<arr2[i]<<" "<<arr[i]<<endl;
	}

	array<int,5>::iterator itr = arr2.begin();

	while( itr != arr2.end())
	{
		cout<<*itr<<" ";
		itr ++;
	}
}
