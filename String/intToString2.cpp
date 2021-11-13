#include <bits/stdc++.h>
using namespace  std;


string to_string(int num)
{
	stringstream ss;

	ss<<num;

	string s;
	ss>>s;

	return s;
}

int sumDigit( string s)
{
	if(s.length() == 1)
		return s[0] - '0';  // because we want to take the character value
	int sum=0;

	for (int i = 0; i < s.length(); ++i)
	{
		sum += s[i] - '0';   // example:-  3 has ascii value of 50 so we need to subtrac ascii value of 48 ( '0 ')
	}

	return (sumDigit(to_string(sum)));

}




int main()
{
	
	string n;
	int k;

	cin>>n;
	cin>>k;

	int x = sumDigit(n);

	int t =0;

	while( k-- )
	{
		t += x;
	}

	cout<<sumDigit(to_string(t))<<endl;

	return 0;
}