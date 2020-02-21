#include<bits/stdc++.h>
using namespace std;

int min(int a[],int n)
{
    int m=a[0];
    
    for(int i=0;i<n;i++)
    {
        if(a[i] < m)
         m=a[i];
    }
    
    return m;
}

int main()
{
    int t;
    cin>>t;

    while( t-- )
    {
        int n;
        cin>>n;

        int utk=0;
        int shr=0;

        int a[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }


        for(int i=0;i<n;i++)
        {
            shr += a[i] - 1;
        }
        
        utk = min(a,n) - 1;

        cout<<utk<<" "<<shr<<endl;

    }


    
}