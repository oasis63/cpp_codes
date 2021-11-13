#include<bits/stdc++.h>
using namespace std;

void print(multimap<string,int>m){
    multimap<string,int>::iterator itr=m.begin();

    while(itr!=m.end()){
        cout<<itr->first<<" "<<itr->second<<endl;
        itr++;
    }
}

int main(){

    multimap<string,int> mm;

    mm.insert(make_pair("Rohan",0));
//    mm["Rajesh"] = 1;
//    mm["Robin"] = 34;
//    mm["marvel"] = 33;
    mm.insert(make_pair("r",4));
    mm.insert(make_pair("same",45));
    mm.insert(make_pair("same",34));

    print(mm);
}
