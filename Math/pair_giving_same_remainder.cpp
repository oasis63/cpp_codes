#include <bits/stdc++.h>
using namespace std;

#define ll  long int


int solve(int n,int k){
    int count=0;
    for(int i=1;i<=n;i++){
        for(int j=(i+k);j<=n;j+=k){
            count++;
        }
    }
    return count;
}



int main(){
    ll n,k;cin>>n>>k;
    ll count = 0;

    cout<<solve2(n,k)<<endl;
}
