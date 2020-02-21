//vector template class
#include<bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
	return a>b;
}

int main()
{
	vector <int> v1;
	v1 = {5,9,10,1,2,3,4};

	sort(v1.begin(),v1.end(),comp);

	for(int i=0;i<v1.size();i++)
	{
		cout<<v1[i]<<endl;
	}
	
	cout<<"\n  Size : ";

	cout<<v1.size()<<endl;
	
	cout<<"Enter the number of elements to be inserted"<<endl;
	int t;
	cin>>t;
	
	vector<int> v2(t);
	
	for(int i=0;i<t;i++)
	{
		cin>>v2[i];
	}
	
	for(int i=0;i<v2.size();i++)
	{
		cout<<v2[i]<<endl;
	}
}
