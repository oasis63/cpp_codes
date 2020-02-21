#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>>v;

    int n;
    cin>>n;

    int a;
    int b;

    for(int i=0;i<n;i++)
    {
        cin>>a>>b;

        v.push_back(make_pair(a,b));
    }

    for(int i=0;i<n;i++)
        cout<<v[i].first<<" " << v[i].second<<endl;


    cout<<"\nAfter sorting the elements \n"<<endl;

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++)
        cout<<v[i].first<<" " << v[i].second<<endl;

}
