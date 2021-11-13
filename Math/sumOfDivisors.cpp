// sum of divisors of 3 , below given number

#include <bits/stdc++.h>
using namespace std;

int sumOfDivisors(int m,int noDivisors)
{
	int sum = 0;

	sum = m*(noDivisors*(noDivisors+1))/2;

	return sum;
}

int main()
{
    int n,m;
    cout<<"Enter a number for which , you want to find out the sum of diviisors"<<endl;
    cin>>m;

    cout<<"Enter a number upto which, you want to find out the divisors"<<endl;
	cin>>n;    

    int noDivisors = (n-1)/m;

    cout<<sumOfDivisors(m,noDivisors)<<endl;
}

