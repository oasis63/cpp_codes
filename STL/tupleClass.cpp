//tuple template class
#include<iostream>
#include<tuple>
using namespace std;

int main()
{
	tuple <string,int,int> t1;
	t1 = make_tuple("ayush",3,9);

	cout<<get<0>(t1)<<endl;
	cout<<get<1>(t1)<<endl;
	cout<<get<2>(t1)<<endl;
}