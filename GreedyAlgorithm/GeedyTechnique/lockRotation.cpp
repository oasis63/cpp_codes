/*
Minimum rotations to unlock a circular lock
*/
#include<bits/stdc++.h>
using namespace std;

int solve(int input,int unlock){

    int rotation = 0;
    int input_digit,unlock_digit;

    while(input || unlock){

        input_digit = input%10;
        unlock_digit = unlock%10;

        rotation += min(abs(unlock_digit-input_digit),10-abs(unlock_digit-input_digit));

        input/=10;
        unlock/=10;
    }

    return rotation;
}

int main(){

    int input = 2345;
    int unlock = 5432;

    cout<<solve(input,unlock)<<endl;

    input = 1919;
    unlock = 0000;

    cout<<solve(input,unlock)<<endl;
}


