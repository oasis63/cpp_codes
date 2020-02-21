#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;

    set<int>s;


    for(int i=0;i<str.length();i++)
    {
        s.insert(str[i]);	// storing the string as the ascii values of the string
    }

    if( str.size() == 0)
        cout<<"Empty String"<<endl;
    else
    {
        set<int>::iterator itr = s.begin();

        while( itr != s.end() )
        {
            printf("%c", *itr);
            itr++;
        }
    }

    cout<<endl;
}
