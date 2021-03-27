#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
#define ui unsigned int 

bool isPrime(ui n){
    if(n == 1)
        return false;
    ui s = sqrt(n);
    for(ui i=2;i<=s;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main(){
    int n;cin>>n;
    ll a,b;
    while(n--){
        cin>>a>>b;
        for(ll i=a;i<=b;i++){
            if(isPrime(i)){
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}