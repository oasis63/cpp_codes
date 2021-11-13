#include <bits/stdc++.h>
using namespace std;

// decimal to binary
void decToBin(int dec)
{
    int r;
    int bin=0;
    int j=1;

    while(dec)
    {
        r=dec%2;
        bin=bin+r*j;
        j=j*10;
        dec=dec/2;
    }

    cout<<"bin :"<<bin<<endl;
}

// binary to decimal
void binToDec(int bin)
{
    int dec=0;
    int j=1;
    int r;

    while(bin!=0)
    {
        r=bin%10;

        if(r!=0 && r!=1)
        {
            cout<<"Not Valid Input"<<endl;
            return;
        }

        dec = dec + r*j;
        j=j*2;
        bin=bin/10;
    }
    cout<<dec<<endl;
}

//  decimal to octal
void decToOct(int dec)
{
    int oct=0;
    int j=1;

    while(dec!=0)
    {
        int r=dec%8;
        oct=oct+r*j;
        j=j*10;
        dec=dec/8;
    }

    cout<<oct<<endl;
}

// change from decimal to any base number
void changeDec(int dec,int base)
{
    int ans=0;
    int j=1;

    while(dec!=0)
    {
        int r=dec%base;
        ans=ans+r*j;
        j=j*10;
        dec=dec/base;
    }

    cout<<ans<<endl;
}


int main()
{
    int dec;
    cin>>dec;
    changeDec(dec,2);

    int bin;
    cin>>bin;
    binToDec(bin);

    cout<<endl;
    cout<<"Octal : ";
    changeDec(dec,8);



}
