#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll  min(ll  a,ll  b,ll  c)
{
    ll  m=a<b?a:b;
    m=m<c?m:c;

    return m;
}

ll  gcd(ll  a,ll  b,ll  c)
{
    ll  m = min(a,b,c);

    for(ll  i=m;i>0;i--)
    {
        if( a%i == 0 && b%i==0 && c%i ==0)
                return i;
    }
}

int   main()
{
    ll  t;
    cin>>t;
    
    while ( t-- )
    {
        ll  n;
        cin>>n;
        
        if( n < 3)
            cout<<-1<<endl;
        else
        {
            ll  max = 1;
            ll  a,b,c;
           for(ll  i=n;i>=3;i--) 
           {
               ll  g = gcd(i,i-1,i-2);
               
               if( g >= max)
               {
                   max=g;
                   a=i-2;
                   b=i-1;
                   c=i;
               }
           }
           
           cout<<a<<" "<<b<<" "<<c<<endl;
            
        }
    }
}
