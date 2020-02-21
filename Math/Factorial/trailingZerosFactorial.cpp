#include<bits/stdc++.h>
using namespace std;


// Trailing Zeros in the factorial 

void solve(int n){
    int ans = 0,temp=0;

    while(n>0){
        temp = n/5;
        ans += temp;
        n=temp;
    }

    cout<<ans<<endl;
}


int main(){
    
    int n = 4;
    solve(n);

    return 0;
}