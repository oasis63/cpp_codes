//cyling rotation of the small alphabets

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter a string"<<endl;
    cin>>s;

    int t;
    cout<<"\nEnter the integer of position shift"<<endl;
    cin>>t;

    for(int i=0;i<s.length();i++)
    {
        int diff = s[i] - 96;  // finding the position of the character
        int pos = (diff+t)%26;  // finding the position of the shifted character 

        if( pos == 0)    // when the difference diff is 25 ... shift added to alphabet 'z'
        {
            s[i] = s[i] + t;    // this is the case when the sifted alphabet is 'z'
        }
        else
        {
            s[i] = pos + 96;
        }
        
    }

    cout<<s<<endl;
}
