#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
    
    map<int,int>mp;
    
    mp[1] = 1;
    mp[2] = 2; 
    mp[3] = 3;
    mp[4] = 4;
    mp[5] = 5;


    for(pair<int,int>p: mp){
        // cout<<p.first<<"  "<<p.second<<endl;
        if(p.second == 3){
            mp[p.first] = -1;
        }
    }

     for(pair<int,int>p: mp){
        cout<<p.first<<"  "<<p.second<<endl;
    }


    return 0;
}