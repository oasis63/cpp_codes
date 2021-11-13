#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define range 1000001

ll palArr[range];

bool isPalindrome(ll n){

    ll num=n;
    ll rev = 0;

    while(num){
        ll rem = num%10;
        rev = rev*10+rem;
        num=num/10;
    }

    if(rev==n)
        return true;
    return false;
}

int  main(){

    for(ll i=0;i<10;i++)
        palArr[i]=1;

    for(ll i=10;i<range;i++){
            if(isPalindrome(i)){
                palArr[i]=1;
            }
    }

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;

        for(ll i=n+1;i<range;i++){
            if(palArr[i]){
                cout<<i<<endl;
                break;
            }
        }
    }


}
