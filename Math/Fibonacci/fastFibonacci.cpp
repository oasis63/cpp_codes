#include <bits/stdc++.h>
using namespace std;

int fiboArr[1001]={0};

// top -down approach

int fibo(int n){

    if(fiboArr[n] == 0){
        if(n<=1)
            fiboArr[n]=n;
        else
            fiboArr[n] = fibo(n-1) + fibo(n-2);
    }
    return fiboArr[n];
}


int main()
{
    for(int i=0;i<10;i++)
        cout<<fibo(i)<<endl;
}
