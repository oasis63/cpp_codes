#include <bits/stdc++.h>
using namespace std;

void  twoMaximums(vector<int> v)
{
    int g=0;
    int max = v[0];

    for(int i=0;i<v.size();i++)
    {
        if( v[i] > max)
        {
            max=v[i];
            g=i;
        }
    }

    int secondMax;

    if( g == 0)
        secondMax=v[v.size()-1];
    else
        secondMax=v[0];

    int sm = 0;

    for(int i=0;i<v.size();i++)
    {
        if(v[i] > secondMax && i != g)
        {
            secondMax = v[i];
            sm=i;
        }
    }

    cout<<"max "<<max<<endl;
    cout<<"secondMax "<<secondMax<<endl;

}

int main()
{
    vector<int> v;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    isAns(v);

}