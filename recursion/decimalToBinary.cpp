#include<bits/stdc++.h>
using namespace std;

void decToBin(int n){
    if(n<=1)
        cout<<n;
    else{
        decToBin(n/2);
        cout<<n%2;
    }
}

int main(){
    
    decToBin(173);

    return 0;
}