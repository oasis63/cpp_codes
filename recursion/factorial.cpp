#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

ll fact(ll n)
{
    if( n==0)        // if(n==0 || n==1)
        return 1;
    else
    return(n*fact(n-1));
}

int main()
{
   while(1)
   {
         ll n;
         cin>>n;

        cout<<fact(n)<<endl;
   }
}

