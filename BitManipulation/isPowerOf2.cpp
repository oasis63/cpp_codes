#include <bits/stdc++.h>
using namespace std;

// how to check a number is power of two or not
// Naive method
bool isPower2(int n){
    if(n==0)
        return false;
    else{

        while(n%2==0)
            n=n/2;
        if(n==1)
            return 1;
        else
            return false;
    }

}

// Better approach using bit manipulation

bool isPowerOf2(int n){
    if(n==0)
        return false;
    else{
        /* n&(n-1) == 0 if n is power of 2
            n = 4; n-1 = 3; 100&011 = 0
        */

        if((n&(n-1)) == 0 )
            return true;
        else
            return false;

    }

}


int main(){

    int n;cin>>n;
    cout<<isPowerOf2(n)<<endl;

    return 0;
}
