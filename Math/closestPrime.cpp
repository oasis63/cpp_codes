#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    int t = sqrt(n);

    if( n==1 || n==0)
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

   int greaterPrime=0;   // closest greater prime number
   int lesserPrime = 0;  // closest lesser prime number

   int get1=0;

   for(int i=n;i>=2;i--)
   {
       if (isPrime(i))
        {
            lesserPrime = i;        // closest lesser prime number
            get1=1;
            break;
        } 
   }

   int get2=0;
   int i=n;

   while(get2!=1)
   {

        if( isPrime(i))
        {
            greaterPrime = i;     // closest greater prime number
            get2=1;
            break;
        }

        i++;
   }

   int d1=-1,d2=-1;

   if( lesserPrime != 0)
     d1 = n - lesserPrime;
   
   if( greaterPrime != 0)
     d2 = greaterPrime - n;

    if( d1 < d2 && d1!=-1)
        cout<<"Printed d1 "<<d1<<endl;
    else 
        cout<<"Printed d2 "<<d2<<endl;

   // cout<<lesserPrime<<endl;
   // cout<<greaterPrime<<endl;

}