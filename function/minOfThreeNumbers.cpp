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
    cout<<min(4,5,0)<<endl;
}