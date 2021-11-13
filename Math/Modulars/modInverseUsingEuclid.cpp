//modular multiplicative inverse
#include<bits/stdc++.h>
using namespace std;

int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}



int modInverse(int A, int M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}


int main(){

    cout<<modInverse(7,10)<<endl;
    cout<<modInverse(5,11)<<endl;

    cout<<modInverse(5,11)<<endl;   
    cout<<modInverse(4,5)<<endl;   

}
