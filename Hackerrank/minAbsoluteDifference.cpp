#include <bits/stdc++.h>

using namespace std;

int ans(vector<int>v)
{
    sort(v.begin(),v.end());
    int min = abs(v[0] - v[1]);
    
    for(int i=0;i<v.size();i++)
    {  
            int j=i+1;
            if( abs(v[i] - v[j]) < min && j<v.size() )
            min = abs(v[i] - v[j]);
    }
    
    return ( min);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    // your code goes here
    
    cout<<ans(a)<<endl;
    
    return 0;
}

