//vector template class

#include<iostream>
#include<vector>
using namespace  std;

int main()
{
	vector <int > v1;

	v1.push_back(1);

	v1.push_back(2);

	cout<<v1.front()<<endl;
	cout<<v1.back()<<endl;

	vector <int>:: iterator it = v1.begin();  // iterators are similar to pointers


 	cout<<"\nPrinting the members using iterator  pointer";

	while(it!=v1.end())
	{
		cout<<*it<<endl;
		
		it++;
	}
}