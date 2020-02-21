#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

ll gcd(ll a,ll b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}


int main(){

    ll num1 = 6;
    ll num2 = 63;
    
    ll g = gcd(num1,num2);
    num1 = num1/g;
    num2 = num2/g;
    
    cout<<num1<<"/";
    cout<<num2<<endl;

    return 0;
}