#include <bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cin>>s;

   int shift;
   cout<<"Enter the shifting value"<<endl;
   cin>>shift;

   for(int i=0;i<s.length();i++)
   {
        s[i] = s[i] + shift;

        if( s[i] > 122)
        {
            int diff = s[i] - 122;
            s[i] = 96 + diff;
        }
   }

   cout<<s<<endl;

}