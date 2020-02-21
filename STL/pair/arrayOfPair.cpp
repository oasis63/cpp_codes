#include<bits/stdc++.h>
using namespace std;

int main()
{
    // array of pairs

    int n;cin>>n;
    pair<string,int>p[n];  // more than one same pair can be stored in this array

    for(int i=0;i<n;i++){
        string s ; cin>>s;
        int marks; cin>>marks;
        p[i]=make_pair(s,marks);
    }

    for(int i=0;i<n;i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
}

// we can have two same keys
