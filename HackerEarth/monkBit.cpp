#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    
    
    while( t-- )
    {
        int n;
        cin>>n;
        
        int s[n][32];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<32;j++)
                s[i][j] = 0;
        }

        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;

            int r,index=0;

            while(temp!=0)
            {
                r=temp%2;
                s[i][index] = r;
                temp=temp/2;
                index ++;
            }
        }


        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<32;j++)
        //     {
        //         cout<<s[i][j]<<" ";
        //     }

        //     cout<<endl;
        // }

        int count[32]={0};

        for(int i=0;i<32;i++)
        {
            for(int j=0;j<n;j++)
            {
                if( s[j][i] == 1)
                    count[i]  ++;
            }
        }

        int max=count[0];
        int j=0;

        for(int i=0;i<32;i++)
        {
            if( count[i] > max)
            {    j=i;
                max=count[i];
            }
        }

        cout<<j<<endl;
       // cout<<max<<endl;
        
    }
}
