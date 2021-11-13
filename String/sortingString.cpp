#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;cin>>t;

    string s,sub;
    int n,m;

    while(t--){
        cin>>s;
        cin>>n>>m;

        int len = m-n+1;

        sub=s.substr(n,len);

        sort(sub.rbegin(),sub.rend());

        int index = 0;

        for(int i=n;i<=m;i++){
            s[i]=sub[index];
            index++;
        }

        cout<<sub<<endl;
        cout<<s<<endl;

    }
}
