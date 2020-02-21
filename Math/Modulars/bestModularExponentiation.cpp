#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int pow(int x,int n,int p){

    if(x==0)
        return 0;

     if(n==0)
        return 1%p;

    long long ans = 1,base = x;

    while( n > 0){
        if(n%2 == 1){
            ans = (ans*base)%p;
        }
        base = (base*base)%p;
        n = n/2;
    }

    if(ans < 0)
        ans = (ans + p )%p;

    return ans;

}

int main(){
    
    cout<<pow(2,3,3)<<endl;

    cout<<pow(-1,1,20)<<endl;

    cout<<pow(0,0,1)<<endl;

    cout<<pow(0,0,2)<<endl;

    return 0;
}