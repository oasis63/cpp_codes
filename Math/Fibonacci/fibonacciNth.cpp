#include<bits/stdc++.h>
using namespace std;

int fibo(int n){

    int a = 0,b=1,c;

    if(n==0)
        return a;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }

    return b;
}

int main(){
    int n = 9;

    cout<<"9th term " << fibo(9)<<endl;

    for(int i= 1; i<=10;i++){
        cout<<i<<"   "<<fibo(i)<<endl;
    }

    return 0;
}
