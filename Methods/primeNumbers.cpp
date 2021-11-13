#include <bits/stdc++.h>
using namespace std;

#define range 1000002

int primeArray[range];

void setPrime(){

    for(int i=0;i<range;i++)
        primeArray[i]=1;

    primeArray[0]=0;
    primeArray[1]=0;

    for(int i=2;i<sqrt(range);i++){
        if(primeArray[i]){
            for(int j=i*i;j<range;j+=i){
                primeArray[j]=0;
            }
        }
    }
}

int main(){

    setPrime();

    for(int i=0;i<1000;i++){
        if(primeArray[i])
            cout<<i<<endl;
    }



}
