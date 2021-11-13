#include <bits/stdc++.h>
using namespace std;

void print(std::vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}

bool myWay(int i,int j)
{
     return( i> j);
}

int main() 
{
    int n;
    cin>>n;

    vector<int> v;

    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }

    // sort descendingly

    sort(v.rbegin(),v.rend());  // method #1

    //sort(v.begin(),v.end(),myWay);  //  method #2

    cout<<"\nSort decreasingly "<<endl;
    print(v);

    // sort increasingly

    sort(v.v.begin(), v.end());

    cout<<"\nSort increasingly "<<endl;
    print(v);
}
