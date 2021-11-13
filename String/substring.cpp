#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
	string str,sub;
	cout<<"\nEnter a string\n";
	cin>>str;

	int ipos,lenSub;
	cout<<"\nEnter the initialPosition and length of the substring"<<endl;
	cin>>ipos>>lenSub;

	sub = str.substr(ipos,lenSub);  // str.substr(initialPosition,lengthOftheSubString);

	cout<<sub<<endl;

	return 0;
}
