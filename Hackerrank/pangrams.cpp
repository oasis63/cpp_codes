#include <bits/stdc++.h>
using namespace std;

bool isPangram(int hash[],int n)
{
    bool set = true;
    for(int i=65;i<=90;i++)
    {
        if( hash[i] == 0)
        {
            set = false;
        }
    }

    return set;
}

int main()
{
    int hash[100] = {0};

    string s;

    getline(cin,s);

    for (size_t i = 0; i < s.length(); i++)
    {
        if( s[i] > 90)
        {
            s[i] = s[i] -32;
            hash[s[i]] ++;
        }
        else
        {
            hash[s[i]] ++;
        }
    }

    cout<<"Entered string is: "<<endl;
    cout<<s<<endl;

    cout<<"\nEntered String is ";

    if( isPangram(hash,100))
        cout<<"pangram"<<endl;
    else
        cout<<"not pangram"<<endl;
}
