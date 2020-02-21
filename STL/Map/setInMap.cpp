#include <bits/stdc++.h>
using namespace std;

int main(){

   cout<<"\n\n----- Set in Map ------ \n"<<endl;

    map<int,set<int>> sumElemHash;
    set<int> st1{1,2};
    set<int> st2{1,4};
    set<int> st3{1,6};
    set<int> st4{0,3};
    set<int> st5{3,2};

    sumElemHash[3] = st1;
    sumElemHash[3] = st4;
    sumElemHash[5] = st2;
    sumElemHash[5] = st5;
    sumElemHash[7] = st3;


    for(auto it = sumElemHash.begin();it!=sumElemHash.end();it++){
        cout<<it->first<<"\t----\t";
        set<int> tempset = it->second;
        for(auto j=tempset.begin();j!=tempset.end();j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }



}
