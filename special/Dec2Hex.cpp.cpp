#include<bits/stdc++.h>
using namespace std;

int main()
{
    int dec;
    cin>>dec;

    char hex[]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    string s;

    while(dec)
    {
        int r=dec%16;
        s=hex[r]+s;
        dec=dec/16;
    }

    cout<<s<<endl;
}
