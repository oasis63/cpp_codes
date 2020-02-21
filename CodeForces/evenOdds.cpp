#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    
    ll n,k;
    cin>>n>>k;

    if(n%2==0){  // n is even 

        ll mid = n/2;

        if(k<=mid){
            cout<<(2*k-1)<<endl;
        }else{
            k=k-mid;
            cout<<2*k<<endl;
       }

    }else{  // n is odd

        ll odd = (n/2) + 1;
        ll even = n/2;

        if(k<=odd){
            cout<<(2*k-1)<<endl;
        }else{
            k=k-odd;
            cout<<2*k<<endl;
        }


    }

    return 0;
}