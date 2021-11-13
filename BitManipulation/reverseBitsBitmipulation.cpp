#include<bits/stdc++.h>
using namespace std;

#define ui  unsigned int

ui swapBits(ui x,ui i,ui j){

    ui low = ((x >> i) & 1);
    ui high = ((x >> j) & 1);

    // cout<<"\t low : "<<low<<"\t high :"<<high;

    if(low ^ high){
        // cout<<"\t x : "<<x;
        x ^= ((1U << i) | (1U << j));
    }

    // cout<<"\tx : "<<x<<endl;

    return x;

}


ui reverse(ui x){

    ui n = sizeof(x)*8;

    for(ui i = 0 ;i < n/2;i++){
        x = swapBits(x,i,n-i-1);
    }
    return x;
}


int main(){

    cout<<reverse(3)<<endl;

}

/*

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000

    ans : 0


Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000

    ans : 3221225472



*/