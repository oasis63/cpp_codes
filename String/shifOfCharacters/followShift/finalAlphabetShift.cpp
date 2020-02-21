//cycling rotation of the small alphabets

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int k;
    cin>>k;
    
    k=k%26;

    for(int i=0;i<s.length();i++)
    {
        if( s[i] >= 97 && s[i] <= 122)
        {

            int diff = s[i] - 96;
            int temp = (diff+k)%26;     // rotation of the alphabets

            if( temp == 0)
            {
                s[i] = diff + k + 96;
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
                s[i] = diff + k + 64;
            }
            else
            {
                s[i] = temp + 64;
            }  
        }

        
    }

    cout<<s<<endl;
}
