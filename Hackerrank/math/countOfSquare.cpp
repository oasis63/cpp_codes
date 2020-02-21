#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}

int solve(int a,int b){
    if(a==b)
        return 1;

    int prod = a*b;
    int g = gcd(a,b);
    g*=g;

    return prod/g; 
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int a,b;
        cin>>a>>b;

        cout<<solve(a,b)<<endl;
    }
}