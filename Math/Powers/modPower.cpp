#include<bits/stdc++.h>
using namespace std;

long long d, x, y;
void extendedEuclid(long long A, long long B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        long long temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}



long long modInverse(long long A, long long M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}

long long modExpo(long long x,long long n,long long M){

    long long ans = 1;

    while(n>0){
        if(n&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        //cout<<x<<endl;
        n=n/2;
    }
    return ans;
}

int power(int a, int b, int m) {
    
    if(a<0){
        while(a<0){
            a += m;
        }
    }
    
    if(a==0)
        return 0;
    
    if(b<0){
        a = modInverse(a,m);
        b=b*-1;
    }
    
    return modExpo(a,b,m);
    
}


int main(){

    int tc;
    cin>>tc;

    while(tc--){
        int a,b,m;
        
        cout<<power(a,b,m)<<endl;
    }


    return 0;
}