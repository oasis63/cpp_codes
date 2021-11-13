/*
count the total unordered pair of 
chocolates such that their number of divisors are  same.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define SIZE  1000001
bool primes[SIZE];

set<ll> primeSet;

void setPrimes(){

    for(ll i=0;i<SIZE;i++){
        primes[i]=true;
    }

    primes[0]=false;
    primes[1]=false;

    for(ll i=2;i<=sqrt(SIZE);i++){
    
       if(primes[i]){
            for(ll j=i+i;j<SIZE;j+=i){
                primes[j]=false;
            }
       }
        
    } 

    for(ll i=0;i<SIZE;i++){
        if(primes[i]){
            primeSet.insert(i);
        }
    }

} 


ll countDivisors(ll n){

    if(n==1)
        return 1;

    ll cnt = 2;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0){

            if(n/i == i){
                cnt++;
            }else{
                cnt+=2;
            }
        }
    }

    return cnt;
}


int main(){
    
    setPrimes(); 
    
   ll n;
   cin>>n;

   ll mx_len = 1000;

   ll arr[n];
   ll divCount[n];
   memset(divCount,0,sizeof(divCount));


   ll divisors[mx_len];
   memset(divisors,0,sizeof(divisors));

   for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(primes[arr[i]]){
            divCount[i] = 2;
            divisors[2]++;
            continue;
        }

        ll x = sqrt(arr[i]);
        if(x*x == arr[i]  && primes[x]){
            divCount[i]=3;
            divisors[3]++;
            continue;
        }

        divCount[i] = countDivisors(arr[i]);
        divisors[divCount[i]]++;
   }

   
   /*for(ll i=0;i<n;i++)
    cout<<divCount[i]<<" ";*/

    ll ans = 0;
    // cout<<endl;
    for(ll i=0;i<mx_len;i++){
       if(divisors[i]!=0){
            ll x = divisors[i];
            //cout<<x<<" ";
            ans +=  (x*(x-1))/2;
       }
    }
    // cout<<endl;
    cout<<ans<<endl;

    return 0;
}