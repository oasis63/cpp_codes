#include<bits/stdc++.h>
using namespace std;

//Highest power of 2 less than or equal to given number

int solve(int n){

    if(n==0)
        return -1;

    int pw=0;
    while(n>1){
        pw++;
        n=n/2;
    }

    return pow(2,pw);
}

int solve2(int n){
    int res = 0;

    for(int i=n;i>=1;i--){
        if((i&(i-1)) == 0){
            res = i;
            break;
        }
    }

    return res;
}

int main(){

    cout<<solve(19)<<endl;
    cout<<solve(63)<<endl;

    for(int i=0;i<40;i++){
        cout<<i<<" : "<<solve2(i)<<endl;
    }

}
