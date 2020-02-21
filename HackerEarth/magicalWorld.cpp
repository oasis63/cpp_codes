#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	int t;
	cin>>t;

	while( t-- )
	{
		int n;
		cin>>n;

		string s;
		cin>>s;

		for(int i=0;s[i]!='\0';i++)
		{
			int temp = s[i];
			
			if( temp >= 65 && temp <= 69)
				s[i] = 67;
			else if( temp >= 70 && temp <= 72)
				s[i] = 71;
			else if( temp >= 73 && temp <= 76) 
				s[i] = 73;
			else if( temp >= 77 && temp <= 81)
				s[i] = 79;
			else if( temp >= 82 && temp <= 86) 
				s[i] = 83;
			else if( temp >= 87 && temp <= 93) 
				s[i] = 89;			
			else if( temp >= 94 && temp <= 99) 
				s[i] = 97;
			else if( temp >= 100 && temp <= 102) 
				s[i] = 101;
			else if( temp >= 103 && temp <= 105) 
				s[i] = 103;
			else if( temp >= 106 && temp <= 108) 
				s[i] = 107;
			else if( temp >= 109 && temp <= 111) 
				s[i] = 109;
			else if( temp >= 112 && temp <= 125) 
				s[i] = 113;
			else
				s[i] = 67;
			
		
		}

		cout<<s<<endl;
	}

	
}
