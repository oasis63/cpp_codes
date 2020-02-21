#include <bits/stdc++.h>
using namespace std;

#define ll long  long 

int main(){
    
    
    ll arrLen = 1000001;
    ll primes[arrLen];

    for(ll i=0;i<arrLen;i++){
        primes[i]=1;
    }

    primes[0]=0;
    primes[1]=0;

    for(ll i=2;i<=sqrt(arrLen);i++){
    
        for(ll j=i*i;j<=arrLen;j+=i){
            primes[j]=0;
        }
        
    }
    
    for(ll i=0;i<arrLen;i++){
        if(primes[i])
            primes[i]=i;
    }
    
    for(ll i=1;i<arrLen;i++){
        primes[i]+=primes[i-1];
    }
    
    
    int tc; 
    scanf("%d",&tc);
    ll l,r;
    while(tc--){
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",primes[r]-primes[l-1]);
    }

}

/*
    IN:-
    
    2
    1 6
    4 13
    
    OUT:-
    
    10
    36


*/
