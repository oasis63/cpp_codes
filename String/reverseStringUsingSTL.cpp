#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        string s;cin>>s;

        string sr = s;

        reverse(sr.begin(),sr.end());

        if(sr==s)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
