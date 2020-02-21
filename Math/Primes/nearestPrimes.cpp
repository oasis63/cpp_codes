#include<bits/stdc++.h>
using namespace std;



#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
#define SIZE  1000001
ll primes[SIZE];
ll primeArr[SIZE];

void setPrimes(){

    for(ll i=0;i<SIZE;i++){
        primes[i]=1;
    }

    primes[0]=0;
    primes[1]=0;

    for(ll i=2;i<=sqrt(SIZE);i++){
        if(primes[i]){
            for(ll j=i*i;j<=SIZE;j+=i){
                primes[j]=0;
            }
        }
    }

}

ll solve(ll n){

    ll down = n;
    ll up = n;

    while(1)
    {
        down--;

        if(primeArr[down])
        {
            //printf("%lld\n",p[down]);
            //break;
            return down;
        }

        up++;

        if(primeArr[up])
        {
           // printf("%lld\n",p[up]);
           // break;
            return up;
        }
    }

}

void findNearestPrime(){

    primes[0]=2;
    primes[1]=2;

    for(int i=2;i<SIZE;i++){
        if(primes[i]){
            primes[i]=i;
        }
    }

    primes[4]=3;

     for(int i=5;i<SIZE;i++){
        if(primes[i]==0){
            primes[i]=solve(i);
        }
    }


}


int main(){
    fast;
    setPrimes();

    for(ll i=0;i<SIZE;i++){
        primeArr[i] = primes[i];
    }

    findNearestPrime();

   for(int i=0;i<SIZE;i++){
       cout<<i<<" "<<primes[i]<<endl;
   }

   /* ll tc;cin>>tc;
    while(tc--){
        ll n;cin>>n;
        cout<<primes[n]<<endl;
    }
*/
    return 0;
}
