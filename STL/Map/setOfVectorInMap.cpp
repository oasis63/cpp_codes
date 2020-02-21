#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"\n\n----- (Vector of Set) in Map ------ \n"<<endl;

    map<int,set<vector<int>>> vecsetmap;
    vector<int> vect1{1,2};
    vector<int> vect2{1,4};
    vector<int> vect3{1,6};
    vector<int> vect4{0,3};
    vector<int> vect5{3,2};

    vecsetmap[3].insert(vect1);
    vecsetmap[3].insert(vect4);
    vecsetmap[5].insert(vect2);
    vecsetmap[5].insert(vect5);
    vecsetmap[7].insert(vect3);


    for(auto it = vecsetmap.begin();it!=vecsetmap.end();it++){
        cout<<it->first<<"\t----\n";
        set<vector<int>> tempset = it->second;
        for(auto j=tempset.begin();j!=tempset.end();j++){
            vector<int> t = *j;
            for(int i=0;i<t.size();i++){
                cout<<t[i]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }



}
