//cyling rotation of the small alphabets

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int k;
    cin>>k;

    for(int i=0;i<s.length();i++)
    {
        if( s[i] >= 97 && s[i] <= 122)
        {
            int diff = s[i] - 96;
            int temp = (diff+k)%26;

            if( temp == 0)
            {
                s[i] = s[i] + k;
            }
            else
            {
                s[i] = temp + 96;
            }
        }
        else if( s[i] >= 65 && s[i] <= 90)
        {
            int diff = s[i] - 64;
            int temp = (diff+k)%26;

            if( temp == 0)
            {
                s[i] = s[i] + k;
            }
            else
            {
                s[i] = temp + 64;
            }
        }
        
    }

    cout<<s<<endl;
}
