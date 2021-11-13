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
		sum += s[i] - '0';   // example:-  3 has ASCII value of 50 so we need to subtract ASCII value of 48 ( '0 ')
	}

	return (sumDigit(to_string(sum)));

}

// string to_string2(int num)
// {
// 	while
// }




int main()
{

	string s1,s2;
	cin>>s1>>s2;



	//s1.append(s2);

	//s1.append(s2,1,2);  // s1.append(s2,initialPosition,length Of SubString);

	//s1.append("dots are cool",5);  //  s1.append("string ", length of the sub string);

	//s1.append("Direct inserts this string");

	//s1.append(10,'.');   // s1.append(noOfTimes,character);

	//s1.append(s2.begin()+1,s2.end());

	s1.append<int>(1,53);   // s1.append<int>(no Of Times int to be inserted, ascii value of the int);


	cout<<s1<<endl;
}
