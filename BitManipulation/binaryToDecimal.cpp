#include<stdio.h>

int max(x,y)
int x,y;
{
    return x>y?x:y;
}

int binaryToDecimal2(string b){
    int r,j=1,d=0;
    for(int i=b.length()-1;i>=0;i--)
    {
        r=b[i]-48;
        d=d+r*j;
        j=j*2;
    }

    return d;
}

int decimalToBinary(int n){
    int bin=0;

    int j=1;

    while(n){
        int r = n%2;
        bin = bin + r*j;
        j*=10;
        n=n/2;
    }

    return bin;
}


int binaryToDecimal(int b){
    int r,j=1,d=0;
    while(b!=0)
    {
        r=b%10;
        d=d+r*j;
        j=j*2;
        b=b/10;
    }

    return d;
}




void main()
{
    printf("%d\n",max(3,4));
    printf("%d\n",max(343,443));
}
