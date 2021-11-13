//use of stl
#include<iostream>
#include<array>
using namespace std;

int main()
{
	array <int,6> a = {1,5,3,4,2};

    array <int,6> a1 = { 1,1,1};

	int i;

	for(i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
    }

    cout<<endl;

    cout<<a.at(2)<<endl;

    cout<<a.front()<<endl;

    cout<<a.end()<<endl;

    cout<<a.back()<<endl;

    cout<<a.size()<<endl;

    /*  a.fill(10);        //filling the whole array with 10

    for(i=0;i<6;i++)
        cout<<a[i]<<" "; */


    a.swap(a1);                   //swaping the elements of array a1 to a

    for(i=0;i<6;i++)
        cout<<a.at(i)<<" ";


}
