#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

int climbStairsMap(int n) {
    if(mp[n] == 0){
        if(n<=1)
            mp[n] = 1;
        else
            mp[n] = climbStairsMap(n-1)+climbStairsMap(n-2);
    }
    return mp[n];
}

int main(){
    
    for(int i = 0;i<=45;i++){
        cout<<i<<"  "<<climbStairsMap(i)<<endl;
    }

    return 0;
}