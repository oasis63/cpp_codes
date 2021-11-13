#include <bits/stdc++.h>
using namespace std;

template<class X,class Y>
class Student
{
	private:
		X roll;
		Y name;
	public:
		Student(X r,Y n)
		{
			roll = r;
			name = n;
		}
	
		void show();

};
template<class X,class Y>
void Student<X,Y>::show()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Roll NO.: "<<roll<<endl;
}

int main ()
{
	Student<int,string> s(45,"Jack Frost");
	s.show();
	return 0;
}

