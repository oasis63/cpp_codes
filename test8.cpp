#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 

pair<bool,unsigned long long> check(unsigned long long n){
    pair<bool,unsigned long long> result = make_pair(false,0);
    double sq = sqrt(n);
    unsigned long long steps = (unsigned long long)sq;
    cout<<"sq : "<<sq<<endl;
    cout<<"steps : "<<steps<<endl;
    if(sq == steps){
        result.first = true;
        result.second = steps;
    }
    return result;
}

string solve(unsigned long long num){
    pair<bool,unsigned long long> ret = check(num*8 + 1);
    ret.second = ( ret.second - 1 )/2;
    string result = "Better Luck Next Time";
    if(ret.first){
        result ="Go On Bob "+ret.second;
    }
    return result;
}

int main(){

    int tc; 
    cin>>tc;
    while(tc--){
        unsigned long long num; // = 10000000000000000;
        cin>>num;
        cout<<solve(num)<<endl;
    }
    return 0;
}