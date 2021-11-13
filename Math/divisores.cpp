#include<bits/stdc++.h>
using namespace std;

int factors(int n)
{
    int count =0;

    for(int i=1;i<=sqrt(n);i++)
    {
        if( n%i == 0)    
        {
            if( n/i == i)
                count ++;
            else
                count += 2;
        }
    }

    return count;
}

int main()
{
   int t,n;
   cin>>t>>n;

   int a[n];

   for(int i=0;i<n;i++)
   {
        a[i] = factors(i+1);
   }

   while( t-- )
   {
       int k;
       cin>> k;

       int count = 0;

       int f = factors(k);

       for(int i=0;i<n;i++)
       {
            if( a[i] < f)
                count ++;
       }

       cout<<count<<endl;
   }


}
