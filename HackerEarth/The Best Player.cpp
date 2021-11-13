#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);  // decrease the time of cin,, cout


   int n,t;
   cin>>n>>t;

   string name[n];
   int q[n];

   for(int i=0;i<n;i++)
   {
       cin>>name[i];
       cin>>q[i];
   }

    // bubble sort neede to short the element

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(q[j+1] > q[j])
            {
                int temp = q[j+1];
                q[j+1] = q[j];
                q[j] = temp;

                string s = name[j+1];
                name[j+1] = name[j];
                name[j] = s;
            }

            else if( q[j+1] == q[j])
            {
                if(name[j] > name[j+1])
                {
                    string s = name[j+1];
                    name[j+1] = name[j];
                    name[j] = s;
                }
            }
        }
    }


    for(int i=0;i<t;i++)
        cout<<name[i]<<endl;


    return 0;
}
