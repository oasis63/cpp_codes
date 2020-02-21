#include<bits/stdc++.h>
using namespace std;

int revNum(int n){

    int rev = 0;

    while(n!=0){
        int r = n%10;
        rev = rev*10 + r;
        n/=10;
    }

    return rev;
}

int main(){

    int n = 12300;

    cout<<revNum(n)<<endl;

    return 0;
}