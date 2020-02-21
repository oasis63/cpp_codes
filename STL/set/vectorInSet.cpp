#include <bits/stdc++.h>
using namespace std;

int main(){

    set<vector<int>> sv;

    vector<int> v1{1,2,3};
    vector<int> v2{1,4};

    sv.insert(v1);
    sv.insert(v1);   // repeated vector
    sv.insert(v2);
    sv.insert(v2);   // repeated vector

    for(auto it = sv.begin();it!=sv.end();it++){
        vector<int> t = *it;
        for(int i=0;i<t.size();i++){
            cout<<t[i]<<" ";
        }
        cout<<endl;
    }


}
