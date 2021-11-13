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
        	k = k % 26;
        
            int diff = s[i] - 96;     // finding the position of the character
            int pos = (diff+k)%26;	  // finding the position of the shifted character 

            if( pos == 0)
            {
                s[i] = s[i] + k;
            }
            else
            {
                s[i] = pos + 96;
            }
        }

        else if( s[i] >= 65 && s[i] <= 90)
        {
        	k = k % 26;
        	
            int diff = s[i] - 64;
            int pos = (diff+k)%26;

            if( pos == 0)
            {
                s[i] = s[i] + k;
            }
            else
            {
                s[i] = pos + 64;
            }
        }

        else if( s[i] >= 48 && s[i] <= 57)
        {
        	k = k%10;
        
            int diff = s[i] - 47;
            int pos = (diff + k)%10;

            if( pos == 0)
            {
                s[i] = s[i] + k ;
            }
            else
            {
                s[i] = pos + 47;
            }
        }
    }

    cout<<s<<endl;
}
