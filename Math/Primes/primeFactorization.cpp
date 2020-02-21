// make an array containing all the prime numbers;
/* A prime number has only two divisors
    one and itself
*/
#include<bits/stdc++.h>
using namespace std;

const int mxm = 30;
const int mod = 1e9+7;

int primes[30];


int noOfDivisors(int n){
    int count=0;

    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i)
                count++;
            else
                count +=2;
        }
    }

    return count;
}

void primeSet(){
    int prime[mxm];   // considering all indices as prime number

     for(int i=0;i<mxm;i++){
        prime[i]=1;
     }


    cout<<endl;

    prime[0]=0;
    prime[1]=0;

    for(int i=2;i<sqrt(mxm);i++){
        if(prime[i]==1){

            for(int j=i*i;j<mxm;j+=i){
                prime[j]=0;
            }
        }
    }

    int index=0;

    for(int i=0;i<mxm;i++){
        if(prime[i])
        {
            primes[index]=i;
            index++;
        }
    }
}

int main(){
    primeSet();

    int x;cin>>x;int ar[x];

    for(int i=0;i<x;i++) cin>>ar[i];

    int n=1;

    for(int i=0;i<x;i++){
        while(ar[i]--){
            n*=primes[i];
        }
    }

    cout<<n<<endl;


}
