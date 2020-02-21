#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int i=0;
    int j=s.length() - 1;

    while( i < j)
    {
        char a=s[i];
        s[i]=s[j];
        s[j] = a;

        i++;
        j--;
    }

    cout<<s<<endl;
}