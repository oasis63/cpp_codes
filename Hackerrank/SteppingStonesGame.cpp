#include<bits/stdc++.h>
using namespace std;


pair<bool,long> check(long n){
    pair<bool,long> result = make_pair(false,0);
    double sq = sqrt(n);
    long steps = (long)sq;
    
    if(sq == steps){
        result.first = true;
        result.second = steps;
    }
    return result;
}


string solve(long num) {
    pair<bool,long> ret = check(num*8 + 1);
    ret.second = ( ret.second - 1 )/2;
    string result = "Better Luck Next Time";
    if(ret.first){
        result ="Go On Bob "+ to_string(ret.second);
    }
    return result;
}

int main(){


    int tc; 
    cin>>tc;
    while(tc--){
         long num; // = 10000000000000000;
        cin>>num;
        cout<<solve(num)<<endl;
    }

    return 0;
}