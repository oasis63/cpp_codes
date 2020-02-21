//cycling rotation of the small alphabets

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    for(int i=0;i<s.length();i++)
    {
        int diff = s[i] - 96;   // finding the position of the character
        int pos = (diff+1)%26; // finding the position after shift 

        if( pos == 0)   // found character is 'z'
        {
            s[i] = s[i] + 1;
        }
        else
        {
            s[i] = pos + 96;
        }
        
    }

    cout<<s<<endl;
}
