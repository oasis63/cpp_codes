#include<bits/stdc++.h>
using namespace std;

int main(){

    pair<int,string>boy;

    boy = make_pair(23,"Mickey");

    cout<<boy.first << " " << boy.second<<endl;

    // array of pair

    pair<int,int>square[10];

    for(int i=0;i<10;i++){
        square[i] = make_pair(i,i*i);
    }

    for(int i=0;i<10;i++){
        cout<<square[i].first <<" --- "<< square[i].second<<endl;
    }

}
