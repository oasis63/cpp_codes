#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n;
    cin>>k;
        
    int sum=0;
    
    vector<int> v;
    
    while( n-- )
    {
        int l,t;
        cin>>l>>t;
        
        sum += l;
        
        if( t== 1)
            v.push_back(l);
    }
    
    sort(v.begin(),v.end());
    
    int len = v.size();
    
    int count = len - k;
    
    for(int i=0;i<count;i++)
    {
        sum = sum - v[i]*2;
    }
    
    
    cout<<sum<<endl;
    
}