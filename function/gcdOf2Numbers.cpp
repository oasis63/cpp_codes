#include <bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
    int m = a<b?a:b;

    return m;
}

int main()
{
    int a,b;
    cin>>a>>b;

    int m = min(a,b);

    for(int i=m;i>0;i--)
    {
        if( a%i ==0 && b%i== 0)
        {
            cout<<"GCD: "<<i<<endl;
            break;
        }
    }
}

/* GCD is always less than the smallest number of the given numbers */