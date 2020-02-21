#include <bits/stdc++.h>
using namespace std;

#define rec(n) for(int i=0;i<n;i++)

int main()
{
    int hash[6] = {0};
    int n;
    cin>>n;
    int a[n];

    rec(n)
    {
        cin>>a[i];
    }

    rec(n)
    {
        hash[a[i]] ++;
    }

    rec(6)
    {
        cout<<hash[i]<<" ";
    }


    return 0;
}
