#include <bits/stdc++.h>
using namespace  std;

int reverse(int n)
{
	int rev = 0;
	int i=1;

	while ( n!= 0)
	{
		int rem = n%10;
		rev  = rev + rem*i;
		i=i*10;
		n = n/10;
	}

	return rev;
}

string to_string(int n)
{
	string s = "";

	int num = reverse(n);

	while( num!= 0)
	{
		int rem = num%10;

		int temp = rem + 48;

		s.append<int>(1,temp);

		num = num/10;
	}

	return s;
}

/* Recursive sum of the digits of a number, untill sum is of single digit

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
	
	string s1,s2;
	//cin>>s1>>s2;

	

	//s1.append(s2);

	//s1.append(s2,1,2);  // s1.append(s2,initialPosition,length Of SubString);

	//s1.append("dots are cool",5);  //  s1.append("string ", length of the sub string);

	//s1.append("Direct inserts this string");

	//s1.append(10,'.');   // s1.append(noOfTimes,character);

	//s1.append(s2.begin()+1,s2.end());

	//s1.append<int>(1,53);   // s1.append<int>(no Of Times int to be inserted, ascii value of the int);

	s1 = to_string(345);

	cout<<s1<<endl;
} 