// split n into maximum composite numbers
#include<bits/stdc++.h>
using namespace std;

/*
    Composite Numbers :-
    4,6,8,9,10,...
*/

int countCompositeSum(int n){

    int rem = n%4;

    if(n<4)
        return -1;

    if(rem==0)
        return n/4;

    if(rem==1){
        if(n<9)
            return -1;

        return (n-9)/4+1;
    }


    if(rem==2)
        return (n-6)/4+1;


    if(rem==3){

        if(n<15)
            return -1;

        return (n-15)/4+2;
    }

}

int main(){

    int n = 99;
    cout<<countCompositeSum(n)<<endl;

    n=10;
    cout<<countCompositeSum(n)<<endl;

}
