#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='i')
        {
            s.erase(i,1);
            i--;
        }

        if( s[i] < 97 || s[i] > 122)
        {
            s.erase(i,1);
            i--;
        }

        // cout<<"Inside"<<endl;
        // cout<<s<<endl;
        // cout<<"length of the string "<<s.length()<<endl;
    }

    cout<<s<<endl;
    cout<<"length of the string "<<s.length()<<endl;

}

/* Example String:-   wii ji  */