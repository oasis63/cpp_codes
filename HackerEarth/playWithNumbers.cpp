#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,q;
   cin>>n>>q;

   int a[n];

   for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=1;i<n;i++)
        a[i] += a[i-1];

    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;

        int tot = r-l+1;

        cout<<tot<<endl;

        if(l==1)
        {
            int temp = a[r-1]/tot;
            cout<<temp<<endl;
            cout<<"\nExecuted1\n"<<endl;
        }
        else
        {
            int temp = (a[r-1]-a[l-2])/tot;
            cout<<temp<<endl;
            cout<<"\nExecuted2\n"<<endl;
        }
    }



    return 0;
}
