#include <bits/stdc++.h>
using namespace std;

// removing duplicate elements from a string

int main()
{
     string s;
     cin>>s;

     sort(s.begin(),s.end());    // sorting the string

     cout<<s<<endl;

     for(int i=0;i<s.length();i++)
     {
        int j=i+1;

        while(s[j]==s[i])
        {
            s.erase(j,1);       // erasing the repeated elements
        }
     }

     cout<<s<<endl;
}