//modular multiplicative inverse
#include<bits/stdc++.h>
using namespace std;

int modularExponentiation(int x,int n,int m){
    if(n==0)
        return 1;
    else if( n%2 == 0)
        return modularExponentiation((x*x)%m,n/2,m);
    else
        return (x*modularExponentiation((x*x)%m,(n-1)/2,m))%m;
}


int modInverse(int A,int M)
{
    return modularExponentiation(A,M-2,M);
}

int modMultInv(int a,int m){
    // a*b=1  ... so range of b is [1,m-1]
    // inverse exists if and only if a m are coprime
    // =>  gcd(a,m) == 1

    a = a%m;
    for(int b=1;b<m;b++){
        if((a*b)%m==1)
            return b;
    }
}

int main(){

    cout<<modMultInv(7,10)<<endl;
    cout<<modMultInv(5,11)<<endl;

    cout<<modInverse(5,11)<<endl;   //
}

/*    Approach 3 (used only when M is prime)

    This approach uses Fermat's Little Theorem.

    The theorem specifies the following: A^M−1≡1(modM)

    By multiplying with A^−1

    both sides,the equation can be rewritten as follows:

    A^-1≡A^M−2(modM)

    The formula for A^−1

    is in the form of exponents. Therefore, modular exponentiation can be used to determine the result.

    For example, if A=5 and M=11 then AM−2(modM)=59(mod11)=9

    is the inverse of 5 under modulo 11.

    int modInverse(int A,int M)
    {
        return modularExponentiation(A,M-2,M);
    }
*/
