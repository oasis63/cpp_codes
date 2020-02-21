#include<bits/stdc++.h>
using namespace std;

// powers of number with big exponential value

// binary exponentiation

int recurPower(int x,int n){

    if(n==0)  // base condition
        return 1;
    else if( n%2 == 0)
        return recurPower(x*x,n/2);
    else
        return x*recurPower(x*x,(n-1)/2);
}

int iterPower(int x,int n){
    int result = 1;

    while(n > 0){

       if(n%2 == 1)
            result = result *x;
       x=x*x;
       n=n/2;
    }
    return result;
}



int main(){

    cout<<recurPower(3,10)<<endl;

    cout<<iterPower(3,10)<<endl;
}
