#include<bits/stdc++.h>
using namespace std;

int main(){

//   map<int,set<vector<int>> > sumElemHash;

    map<int,vector<int>> mp;

    vector<int> v1{1,2,3};
    vector<int> v2{1,4};

    mp[5] = v1;
    mp[19] = v2;

    for(auto it = mp.begin();it!=mp.end();it++){
        cout<<it->first<<"\n\t";
        vector<int> tp = it->second;
        for(int i=0;i<tp.size();i++){
            cout<<tp[i]<<" ";
        }
        cout<<endl;
    }

}
