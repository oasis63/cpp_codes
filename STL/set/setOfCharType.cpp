#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;

    set<char>s;


    for(int i=0;i<str.length();i++)
    {
        s.insert(str[i]);
    }

    if( str.size() == 0)
        cout<<"Empty String"<<endl;
    else
    {
        set<char>::iterator itr = s.begin();

        while( itr != s.end() )
        {
            printf("%c", *itr);
            itr++;
        }
    }

    cout<<endl;
}