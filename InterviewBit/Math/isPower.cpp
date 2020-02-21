/*

Given a positive integer which fits in a 32 bit signed integer, 
find if it can be expressed as A^P where P > 1 and A > 0. 
A and P both should be integers.

*/


#include<bits/stdc++.h>
using namespace std;


int isPower(int n){

    if(n==1)
        return 1;

    for(int i=2;i<=sqrt(n);i++){

        int x = n;
        while(x%i==0){
            x=x/i;
        }

        if(x==1)
            return 1;

    }

    return 0;

}

int main(){

    int n = 4;

    cout<<isPower(n)<<endl;

    return 0;
}
