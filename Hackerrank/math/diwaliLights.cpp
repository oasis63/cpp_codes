#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const ull mod = 100000;

/*
    only one way is there when all lights are not glowing   .. 1 
*/

int main(){

   int tc;
    cin>>tc;
    while(tc--){
        ull n;
        cin>>n;
        ull ans = 2;
        while(n-- >1){
            ans = ((ans%mod) * 2)%mod;
        }
        ans--;
        cout<<ans<<endl;
    }


}

