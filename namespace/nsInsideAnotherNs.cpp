#include <bits/stdc++.h>
using namespace std;

namespace ns1
{
	int n1 = 45;

	class Test
	{
		public:
			void display()
			{
				cout<<"Class of the namespace 1"<<endl;
			}
	};
}

using namespace ns1;

namespace ns2
{
	int n2 = 324;

	Test obj;
}

using namespace ns2;

int main()
{
	cout<<"ns1::n1 = "<<n1<<endl;

	obj.display();
}
