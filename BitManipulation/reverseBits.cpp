#include<bits/stdc++.h>
using namespace std;

#define ui  unsigned int

ui binaryToDecimal(string b){
    int r,j=1;
    ui d=0;
    for(int i=b.length()-1;i>=0;i--){
        r=b[i]-48;
        d=d+r*j;
        j=j*2;
    }

    return d;
}


string decimalToBinary(ui n){
    string bin="00000000000000000000000000000000";

    ui j=31;

    while(n){
        ui r = n%2;
        
        if(r==0)
            bin[j]='0';
        else
            bin[j]='1';

        j--;
        n=n/2;
    }

    return bin;
}


ui reverse(ui n){

    if(n==0)
        return 0;

    //string bin = "00000000000000000000000000000000";

    string bin = decimalToBinary(n);

    int l = 0,h = 31;

    while(l<=h){
        char t = bin[l];
        bin[l]=bin[h];
        bin[h]=t;
        l++;
        h--;
    }

    ui ans = binaryToDecimal(bin);

    return ans;
}


int main(){

    //string bin = "00000000000000000000000000000000";

    // cout<<bin<<endl;
    // string b = decimalToBinary(3);

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