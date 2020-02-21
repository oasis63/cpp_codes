#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;cin>>n;
    string s[n];

    for(int i=0;i<n;i++)
        cin>>s[i];

      // do not use  sort(s.begin(),s.end());.. it is used for STL type classes

    sort(s,s+n);  // it is used for array sort method

    //sort(s,s+n,greater<string>()); // in decreasing order



    for(int i=0;i<n;i++)
        cout<<s[i]<<endl;
}
