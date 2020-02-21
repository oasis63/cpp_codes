#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    int f=1;

    for(int i=1;i<=n;i++)
        f=f*i;
    return f;
}

int permute(int n,int r)  // used for list
{
    int p=n;

    for(int i=1;i<r;i++)
    {
        n--;
        p=p*n;
    }


    return p;
}

int combinat(int n,int r)   // used for group
{
    int c=n;

    for(int i=1;i<r;i++)
    {
        n--;
        c=c*n;
    }

   // cout<<fact(r)<<endl;
    c=c/fact(r);

    return c;
}

int main()
{
    int n,r;
    cin>>n>>r;

    cout<<"Permutation "<<permute(n,r)<<endl;
   cout<<"combination " <<combinat(n,r)<<endl;
}