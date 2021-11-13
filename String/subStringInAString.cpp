#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str,sub;

    cin>>str>>sub;

    int set = 0;

    int len = sub.length();

    for(int i=0;i<str.length();i++)
    {
        if( (i+len) <= str.length())
        {
            string temp = str.substr(i,len);
            
            if( temp == sub)
            {  
                set  = 1;
                break;
            }
        }
    }

    if( set )
        cout<<set<<endl;
    else
        cout<<set<<endl;
}