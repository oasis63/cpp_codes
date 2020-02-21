#include <bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cout<<"Enter a string"<<endl;
   cin>>s;

   // int shift;
   // cout<<"Enter the shifting value"<<endl;
   // cin>>shift;

   for(int i=0;i<s.length();i++)
   {
        s[i] = s[i] - 1 ;

        if( s[i] < 97)
        {
            // int diff = s[i] - 122;

            int diff = 97 - s[i];

            s[i] = 123 - diff;
        }
   }

   cout<<s<<endl;

}