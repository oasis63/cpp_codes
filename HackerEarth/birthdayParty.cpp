#include <bits/stdc++.h>
using namespace std;

#define ll  long long  int  

int  main()
{
   ll  t;
   cin>>t;
   
   while( t-- )
   {
       ll  n,x;
       cin>>n>>x;
       
       ll a[n];
       
       for(ll i=0;i<n;i++)
       {
           cin>>a[i];
       }

       ll  get=0;
       
       for(ll i=0;i<n;i++)
       {
           ll  sum=0;


           for(ll j=i;j<n;j++)
           {
                sum += a[j];

                if( sum == x)
                {
                    get=1;
                    cout<<"YES"<<endl;
                    break;
                }
           }

           if(get)
           {
              break;
           }
        }

        if( get== 0)
        {
            cout<<"NO"<<endl;
        }    
   }
}