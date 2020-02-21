#include<bits/stdc++.h>
using namespace std;


/*

minimum number of steps required to make a number to one c++ program

*/


int prime[100001] = {1};

int maxLen = 100001;

int checkPrime(int n){

    if(n==0 || n==1)
        return 0;

    if(n==2)
        return 1;


    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

void setPrime(){

    for(int i=0;i<100001;i++)
        prime[i] = 1;

    prime[0]=0;
    prime[1]=0;

    for(int i=2;i<maxLen;i++){
        if(prime[i]){
            for(int j=2*i;j<maxLen;j+=i){
                prime[j]=0;
            }
        }
    }
}

int decrement(int n){
    int ret=1;
    for(int i=n-1;i>=2;i--){
        if(prime[i]){
            break;
        }
        ret++;
    }
    return ret;
}

int increment(int n){
    int ret=1;
    int i=n+1;
    while(1){
        if(prime[i]){
            break;
        }
        ret++;
        i++;
    }
    return ret;
}


void solve(int n){
    int steps=0;
    int dec = decrement(n);
    int inc = increment(n);

    if(dec < inc)
        steps = dec + 1;
    else
        steps = inc + 1;

    cout<<steps<<endl;
}

int main()  {

   setPrime();

   int tc;
   cin>>tc;

   while(tc--){
       int n;
       cin>>n;
        if(n==1)
            cout<<0<<endl;
        else if(prime[n]){
            cout<<1<<endl;
        }else{
            solve(n);
        }

   }

    return 0;
}
