#include <bits/stdc++.h>
using namespace std;

void toHex(int dec)
{

    int ans=0;
    int j=1;
    int base=16;
    string s;

    while(dec!=0)
    {
        int r=dec%base;

        switch(r)
        {
            case 10:
                s='A'+s;
                break;
            case 11:
                s='B'+s;
                break;
            case 12:
                s='C'+s;
                break;
            case 13:
                s='D'+s;
                break;
            case 14:
                s='E'+s;
                break;
            case 15:
                s='F'+s;
                break;
        }

        if( r >=10 && r<=15)
        {
            dec=dec/base;
            continue;

        }

        ans=ans+r*j;
        j=j*10;
        dec=dec/base;

    }
    cout<<ans<<s<<endl;
}


int main()
{
    int hex;
    cout<<"Enter a Decimal to get it's Hexadecimal Equivalent "<<endl;
    cin>>hex;

    toHex(hex);

}
