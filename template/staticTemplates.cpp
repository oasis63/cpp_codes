#include<iostream>
using namespace std;

template <class T>
class Test
{	
	public:
		   static int count;
		   T val;
	       Test()
	       {
	         count++;
	       }//end of constructor.
};//end of class

template <class T>
int Test<T>::count=0;

int main()
{
  Test<int> o1;
  Test<int> o2;
  cin>>o1.val;
  cin>>o2.val;
  
  cout<<o1.val<<endl;
  cout<<o2.val<<endl;
  
  cout<<o1.count<<endl;
}
	
		
