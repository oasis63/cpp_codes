#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<string,string> words;
    int m;
    cin>>m;

    string f,s;
    while(m--){
        cin>>f>>s;
        words.insert(make_pair(f,s));
    }

    cout<<endl;

    for(pair<string,string> p : words){
        cout<<p.first<<" "<<p.second<<endl;
    }

    cout<<endl;

    unordered_map<string,string>::iterator itr = words.begin();

    while(itr!=words.end()){
        cout<<itr->first<<" "<<itr->second<<endl;
        itr++;
    }



    return 0;
}

/*

// sample input

3
joll wuqrd
euzf un
hbnyiyc rsoqqveh




*/
