#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> v;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int set=v[0];
    int units=1;

    for(int i=0;i<n;i++)
    {
        if( v[i]>=set && v[i]<=(set+4))
        {
           // cout<<"do nothing"<<endl;
        }
        else
        {
            set=v[i];
            units ++;
        }

        /*
                instead of above if else
                use it 

                if( v[i] > (set+4))
                {
                    set=v[i];
                    units ++;
                }
        */
    }

    cout<<units<<endl;
}