#include <bits/stdc++.h>
using namespace std;

#define size 100001

int prime[50];

int nthPrime[15];

int nthNum[size];

void setPrime(){

    for(int i=0;i<50;i++)
        prime[i]=1;
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<50;i++){

        if(prime[i]==1){
            for(int j=2*i;j<50;j+=i){
                prime[j]=0;
            }
        }
    }
    int index=0;

    for(int i=0;i<50;i++){
        if(prime[i]){
            nthPrime[index]=i;
            index++;
        }
    }

}

int main()
{

   int q,n;
   cin>>q;

   while(q--){
    cin>>n;
    cout<<n+1<<endl;
   }


}
