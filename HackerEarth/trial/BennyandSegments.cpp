#include <bits/stdc++.h>
using namespace std;

int  main()
{
    long int  t;
    cin>>t;

   while(t--)
   {
        long int  n,v;
        cin>>n>>v;

        long int  l[n],r[n];

        for(long int  i=0;i<n;i++)
        {
            cin>>l[i];
            cin>>r[i];
        }

        //  using buuble sort

        for(long int  i=0;i<n-1;i++)
        {
            for(long int  j=0;j<n-i-1;j++)
            {
                if(l[j+1] < l[j])
                {
                    long int  temp = l[j+1];
                    l[j+1] = l[j];
                    l[j] = temp;

                    temp = r[j+1];
                    r[j+1] = r[j];
                    r[j] = temp;
                }

                else if( l[j+1] == l[j])
                {
                    if(r[j+1] < r[j])
                    {
                       long int  temp = r[j+1];
                       r[j+1] = r[j];
                       r[j] = temp;
                    }
                }
            }
        }


        long int  seg=1;

        // counting the no. of segments

        for(long int  i=0;i<n;i++)
        {
            for(long int  j=i+1;j<n;j++)
            {
                if(r[i] == l[j])
                {
                    seg++;
                    i=j;
                    i--;
                    break;
                }
            }

        }

        if(seg == v)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

   }

    return 0;
}
