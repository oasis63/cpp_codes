//vector template class

#include<iostream>
#include<vector>
using namespace  std;

int main()
{
	vector <string> v1(4,"hello");

	v1.push_back("ehllo");

	cout<<v1.size()<<endl;

	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<endl;

	vector <string>::iterator it = v1.begin();

	v1.insert(it+1,"Rajesh");

	for(int i = 0;i<v1.size();i++)
		cout<<v1[i]<<" ";
}