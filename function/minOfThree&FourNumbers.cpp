#include <bits/stdc++.h>
using namespace std;


// HackerEarth

int min(int a,int b,int c)
{
	if ( a < b && a < c)
	{
		return a;
	}
	else if( b < c && b < a)
	{
		return b;
	}
	else
	{
		return c;
	}
}

int min(int a,int b,int c,int d)
{
	if ( a < b && a < c && a < d)
	{
		return a;
	}
	else if( b < c && b < d && b < a)
	{
		return b;
	}
	else if( c < d && c < a && c < b)
	{
		return c;
	}
	else
	{
		return d;
	}
}


int main()
{
	int size;
	string s;
	
	cin>>size;
	cin>>s;
	
	int count = 0;
	
	if( size >= 11)
	{
		map<char,int>m;
	
		for(char t='a';t<='z';t++)
		{
			m[t] = 0;
		}
	
		for(int i=0;s[i]!='\0';i++)
		{
			m[s[i]] ++;
		}
	

	
		int a = m['a'];
		int c = m['c'];
		int e = m['e'];
		int k = m['k'];
		int r = m['r'];
		int h = m['h'];
		int t = m['t'];
	
		int minOne = min(c,k,t);
		int minTwo = min(a,e,r,h);
		
		cout<<"a "<<a<<endl;
		cout<<"c "<<c<<endl;
		cout<<"e "<<e<<endl;
		cout<<"k "<<k<<endl;
		cout<<"r "<<r<<endl;
		cout<<"h "<<h<<endl;
		cout<<"t "<<t<<endl;
		
		

		cout<<"minOne "<<minOne<<endl;
		cout<<"minTwo "<<minTwo<<endl;
	
		while( minOne >= 1 && minTwo >=2)
		{
			minOne -= 1;
			minTwo -= 2;
			count++;
		}
	}
	
	cout<<count<<endl;
	


}
