//vector template class
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector <int> v1;			//declaration of the vector

	cout<<"Initial Capacity = "<<v1.capacity()<<endl;  //maximum number of elements can be inserted
	cout<<"Initial size = "<<v1.size()<<endl;         //actual number of elements in the vector

	v1.push_back(45);                             //function to add element in the vector
	v1.push_back(43);
	v1.push_back(24);
	v1.push_back(29);
	v1.push_back(20);

	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<endl;

	cout<<"Current Capacity = "<<v1.capacity()<<endl;
	cout<<"Current size = "<<v1.size()<<endl;


	v1.pop_back();     //removes an element from the back of the vector ;

	cout<<"Current Capacity = "<<v1.capacity()<<endl;
	cout<<"Current size = "<<v1.size()<<endl;

	cout<<"Front element ="<<v1.front()<<endl;   //gives the first element of the vector
	cout<<"Back element ="<<v1.back()<<endl;	 //gives the last element of the vector

	//adding more element at the end to the vector

	for(int i=0;i<6;i++)
		v1.push_back(i*5);

	cout<<"Current Capacity = "<<v1.capacity()<<endl;
	cout<<"Current size = "<<v1.size()<<endl;

	cout<<"\nVector after adding more elements\n"<<endl;

	for(int i=0;i<v1.size();i++)
		cout<<v1.at(i)<<endl;

	//use of iterator to add elements in the middle of the vector

	vector <int>::iterator it = v1.begin();     

	v1.insert(it+2,1000);

	cout<<"\nAfter adding element in the middle of the vector\n"<<endl;

	for(int i=0;i<v1.size();i++)
		cout<<v1.at(i)<<" ";

	v1.clear();             //function to remove all the elements from the vector

	//vector after removing all the elements

	/*for(int i=0;i<v1.capacity();i++)
		cout<<v1[i]<<endl;*/

	cout<<"Current Capacity = "<<v1.capacity()<<endl;
	cout<<"Current size = "<<v1.size()<<endl;

}