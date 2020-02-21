#include<bits/stdc++.h>
using namespace std;

int binary(int n){

    if(n==0 || n==1)
        return n;
    if(n%2==0)
        return 10*binary(n/2);
    else
        return 10*binary(n/2)+1;
}

int main(){
    for(int i=0;i<=20;i++){
        cout<<i<<"\t"<<binary(i)<<endl;
    }
}