#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    int t = sqrt(n);

    if( n==1 )
        return false;

    for(int i=2;i<=t;i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
   int n;
   cin>>n;
   
   if( isPrime(n))
   	cout<<"Prime"<<endl;
   else
   	cout<<"Not Prime"<<endl;
}
