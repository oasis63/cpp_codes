#include <bits/stdc++.h>
using namespace std;

int  main()
{
	int t;
	cin>>t;

	while( t-- )
	{
		string hack = "hackerrank";
		string str;
		cin>>str;

		int i=0;
		int j=0;

		while( str[j] )   // while(j < str.length)
		{
			if( hack[i] == str[j])
			{
				i++;
			}
			j++;
		}

		if( i == 10)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
}
