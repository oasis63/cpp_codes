#include<bits/stdc++.h>
using namespace std;

/*
    Incorrect Output
*/

const int PRIME_LENGTH = 1000001;

bool primes[PRIME_LENGTH];


bool is_prime(int n){
    if(n==0 || n==1)
        return false;
    else if(n==2)
        return true;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}

void setprimes(){
    for(int i=0;i<PRIME_LENGTH;i++){
        primes[i] = is_prime(i);
    }
}

bool is_possible(int arr[],int n,int pos,int steps){

    if(pos==n-1 && steps>=0){
        return true;
    }else if(pos!=n-1 && steps<=0){
        return false;
    }


    for(int i=pos;i<n;i++){

        for(int p=2;p<=arr[i];p++){

            if(arr[i]%p==0 && primes[p]){

                int ford=0;

                if(pos+p<n){
                    pos=pos+p;
                    steps--;
                    ford=1;
                    if(is_possible(arr,n,pos,steps))
                       return true;

                    pos = pos-p;
                    steps++;
                    ford=0;

                }

                if(pos-p>=0 && ford==0){
                    pos=pos-p;
                    steps--;
                    if(is_possible(arr,n,pos,steps))
                       return true;
                    pos = pos + p;
                    steps++;
                }

                return false;
            }

            if(p==arr[i])
                return false;

        }
        return false;
    }

    return false;
}

int main(){
    int tc;cin>>tc;

    setprimes();

    while(tc--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int steps;cin>>steps;
        if(is_possible(arr,n,0,steps))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}
