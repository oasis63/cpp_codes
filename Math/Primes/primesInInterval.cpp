#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define range 1000002

ll primeArray[range];

void setPrime(){

    for(ll i=0;i<range;i++)
        primeArray[i]=1;

    primeArray[0]=0;
    primeArray[1]=0;

    for(ll i=2;i<sqrt(range);i++){
        if(primeArray[i]){
            for(ll j=i*i;j<range;j+=i){
                primeArray[j]=0;
            }
        }
    }
}
int main(){

    setPrime();

    ll l,r;cin>>l>>r;

    for(ll i=l;i<=r;i++){
        if(primeArray[i])
            cout<<i<<" ";
    }

}
