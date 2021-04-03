#include<bits/stdc++.h>
using namespace std;

#define ui unsigned int
#define SIZE  1000001


int main(){
    map<int,int> countMap;
    int a,b,c;
    cin>>a>>b>>c;
    a=a+b+c;
    int t;
    while(a--){
        cin>>t;
        countMap[t]++;
    }
    vector<int>vect;
    for(pair<int,int>p : countMap){
        if(p.second >= 2){
            // cout<<p.first<<endl;
            vect.push_back(p.first);
        }
    }
    cout<<vect.size()<<endl;
    for(int v : vect){
        cout<<v<<endl;
    }


    return 0;
}