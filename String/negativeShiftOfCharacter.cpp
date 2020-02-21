//cyling rotation of the small alphabets

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter a string"<<endl;
    cin>>s;

    int t;
    cout<<"\nEnter the negative integer of position shift"<<endl;
    cin>>t;

    for(int i=0;i<s.length();i++)
    {
        int diff = s[i] - 96;
        int temp = (diff+t)%26;

        if( temp == 0)
        {
            s[i] = diff + t + 96+26;    // to get the 'z'
        }
        else
        {
            s[i] = temp + 96;
        }
        
    }

    cout<<s<<endl;
}