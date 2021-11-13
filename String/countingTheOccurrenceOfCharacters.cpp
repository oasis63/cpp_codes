#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;


	int len[3]={0};

	int index = 0;

	for(int i=0;i<s.length();i++)
	{
		len[index]=1;

		while( s[i] == s[i+1] && (i+1) < s.length())
		{
			len[index] ++;
			i++;
		}

		index ++;
	}

	for(int i=0;i<3;i++)
		cout<<len[i]<<" ";
}