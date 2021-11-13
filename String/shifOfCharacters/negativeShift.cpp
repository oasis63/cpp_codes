#include <bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cout<<"Enter a string"<<endl;
   cin>>s;

   int shift;
   cout<<"Enter the shifting value"<<endl;
   cin>>shift;

   for(int i=0;i<s.length();i++)
   {
        s[i] = s[i] - shift ;

        if( s[i] < 97)
        {
        
            int diff = 97 - s[i];

            s[i] = 123 - diff;
        }
   }

   cout<<s<<endl;

}