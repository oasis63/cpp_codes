#include <bits/stdc++.h>
using namespace std;

template<class T>
T myMax(T a,T b)
{
	return(a>b?a:b);
}

int main ()
{
	cout<<myMax<int>(3,4)<<endl;
	cout<<myMax<double>(4.2,54.03)<<endl;
	cout<<myMax<char>('a','A')<<endl;
	cout<<myMax<string>("daemon","jack")<<endl;
	return 0;
}


