#include<bits/stdc++.h>
using namespace std;



#define ll  long long


int main(){
   // ios_base::sync_with_stdio(false);cin.tie(0);

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

    for(ll i=2;i<arrLen;i++){
        if(primes[i]==1)
            primes[i] = i;
    }


    ll tc;

    scanf("%lld",&tc);

    while(tc--){
        ll n;

        scanf("%lld",&n);

        if(primes[n])
         printf("%lld\n",n);
        else{

            ll down = n;
            ll up = n;

            while(1)
            {
                down--;

                if(primes[down])
                {
                    printf("%lld\n",primes[down]);
                    break;
                    //cout<<down<<endl;
                }

                up++;

                if(primes[up])
                {
                   printf("%lld\n",primes[up]);
                    break;
                    //return up;
                }
            }

        }
            
    }

    return 0;
        
}
