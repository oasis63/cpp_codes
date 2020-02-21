#include<bits/stdc++.h>
using namespace std;

void print(map<string,int>m){
    map<string,int>::iterator itr=m.begin();

    while(itr!=m.end()){
        cout<<itr->first<<" "<<itr->second<<endl;
        itr++;
    }
}

int main(){

    map<string,int> m;

    m.insert(make_pair("Rohan",0));
    m["Rajesh"] = 1;
    m["Robin"] = 34;
    m["marvel"] = 33;
    m.insert(make_pair("r",4));
    m["same"] = 3;
    m["same"] = 43;

    print(m);
}
