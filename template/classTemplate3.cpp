//Make a template for the class having two data typename

#include <bits/stdc++.h>
using namespace std;

template<class T,class U>
class Test
{
	private:
		T a;
		U b;
	public:
	
		Test(T x,U c)
		{
			a=x;
			b=c;
		}
		
		void show()
		{
			cout<<a<<endl;
			cout<<b<<endl;
		
		}
		
		~Test()
		{
			cout<<"\nDestructing the class Object"<<endl;
		}

};


int main ()
{
	//Test obj1(2,'a'); // try after uncommenting this statement, it would show error
		
	 Test <int,char>obj1(38,'f');
	
	cout<<"\nFirst Object"<<endl;
	obj1.show();
	
//	Test <int,string>obj2;						// it would show error, because we have not defined the default constructor
	
	
	cout<<"\nSecond Object"<<endl;
	Test <int,string>obj2(0,"String");
	obj2.show();
	
	
}



