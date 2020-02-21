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
        int diff = s[i] - 96;
        int temp = (diff+t)%26;

        if( temp == 0)    // when the difference diff is 25 ... shift added to alphabet 'z'
        {
            s[i] = diff + t + 96;    // this is the case when the sifted alphabet is 'z'
        }
        else
        {
            s[i] = temp + 96;
        }
        
    }

    cout<<s<<endl;
}