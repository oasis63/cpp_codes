#include <bits/stdc++.h>
using namespace std;

int main()
{
   
   float f= 3.45;
    
   cout<<ceil(f)<<endl;

   int t=4;

   cout<<ceil(t)<<endl;

   float g  = 5.55;

   cout<<floor(g)<<endl;

  // cout<<(6.5%10)<<endl;

   if( (t-floor(t)) == 0)
        cout<<"Integer"<<endl;
    else
        cout<<"Non-Integer"<<endl;


   if( (g-floor(g)) == 0)
        cout<<"Integer"<<endl;
    else
        cout<<"Non-Integer"<<endl;


}