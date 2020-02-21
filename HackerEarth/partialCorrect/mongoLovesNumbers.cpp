#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

ll noOfDivisors(ll n)
{
    ll  count = 2;
    
    if( n==1 )
        count = 1;
    
    for(ll  i=2;i<=sqrt(n);i++)
    {
        if( n%i ==0)
        {
            count++;
            break;
        }
    }
    
    return count;
}


int main()
{
    ll  t;
    cin>>t;
    
    while( t-- )
    {
        ll  l,r,left,right;
        cin>>l>>r;
        
        if( l < r)
        {
            left = l;
            right = r;
        }
        else
        {
            left = r;
            right = l;
        }
        
        ll  count=0;
        
        for(ll  i=left;i<=right;i++)
        {
            ll  no = noOfDivisors(i);
            
            if( no == 2)
            {
                count++;
            }
        }
        
        cout<<count<<endl;
    }
    
}
