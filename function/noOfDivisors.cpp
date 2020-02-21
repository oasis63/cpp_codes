#include<bits/stdc++.h>
using namespace std;

int divisors(int n){
    int count=0;

    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){         // checking whether the number is divisible by i or not
            if(n/i==i){
                count++;
            }
            else{
                count+=2;
            }
        }
    }
    return count;
}

int main(){

    cout<<divisors(16)<<endl;
    cout<<divisors(20)<<endl;
}
