#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main()
{
    int t;
    cin>>t;
    
    while( t-- )
    {
        
       ull a,b;
       ull sum = 0,q,rem;
       int m;
       cin>>m;
       
       while( m-- )
       {
           cin>>a>>b;
            sum += a*b;
            
       }
       
       if( sum == 0)
        cout<<0<<endl;
       else 
       {
           if( sum > 9 && sum%9 != 0)
           {
                q = sum/9;
                rem = sum - q*9;
               cout<<rem<<endl;
           }
           else if( sum%9==0)
                cout<<9<<endl;
           else 
                cout<<sum<<endl;
       }
        
    }
}