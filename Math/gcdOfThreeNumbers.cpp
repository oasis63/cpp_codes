#include <bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{
    int m = a<b?a:b;
    m=m<c?m:c;

    return m;
}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    int m = min(a,b,c);

    for(int i=m;i>0;i--)
    {
    	if( a%i ==0 && b%i== 0 && c%i== 0)
    	{
    		cout<<"GCD: "<<i<<endl;
    		break;
    	}
    }
}

/* GCD is always less than the smallest number of the given numbers */