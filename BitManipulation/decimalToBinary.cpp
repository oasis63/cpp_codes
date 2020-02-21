#include<bits/stdc++.h>
using namespace std;

int decimalToBinary(int n){
    int bin=0;

    int j=1;

    while(n){
        int r = n%2;
        bin = bin + r*j;
        j*=10;
        n=n/2;
    }
 
    return bin;
}

int main(){

    for(int i = 0 ; i<101;i++){
        cout<<"i = "<<i<<"  " << decimalToBinary(i)<<endl;
    }
}


