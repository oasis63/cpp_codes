#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,string>>v;

    for(int i=0;i<4;i++){
        int n;cin>>n;
        string s;cin>>s;

        pair<int,string>p;
        p=make_pair(n,s);

        v.push_back(p);
    }

    cout<<endl;

    sort(v.begin(),v.end());

    for(int i=0;i<4;i++)
        cout<<v[i].first<<" " <<v[i].second<<endl;

}
