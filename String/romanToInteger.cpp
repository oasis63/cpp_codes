#include<bits/stdc++.h>
using namespace std;

int romInt(char c){

    switch(c){

        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }

}


int romanToInt(string str) {

    int n = str.length();
    int ans = 0;
    int prev = 0;
    for(int i=0;i<n;i++){
        int curr = romInt(str[i]);
        if(prev < curr){
            curr -= prev*2;
        }
        prev=curr;
        ans += curr;
    }
    return ans;
}

int main(){
    string str = "CCXLVI";

    cout<<romanToInt(str)<<endl;
}
