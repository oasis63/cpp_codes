#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 

int weirdStock(int n, int m){
    int res = 0;
    while(n < m){
        m = m & 1 ? m + 1 : m / 2;
        res++;
    }
    return res + (n - m);
}

int main(){

    cout<<weirdStock(3,4)<<endl;

    cout<<weirdStock(10,1)<<endl;

    return 0;
}