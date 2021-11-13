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
    
    sort(v.begin(),v.end());
    
    int gcd = v[0];

    //cout<<"Smallest value "<<gcd<<endl;
    
    while( gcd > 0)
    {
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if( v[i]%gcd == 0)
            count++;
        }
        
        if( count == n)
            break;
        
        gcd --;
    }
    
  //  cout<<gcd<<endl;

    for(int i=gcd;i<v[0];i=i+gcd)
        cout<<i<<" ";
}
