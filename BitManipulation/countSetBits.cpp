#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n){
    int setBits = 0;

    while(n){
        setBits++;
        n=n&(n-1);
    }

    return setBits;
}


int countSetBit2(int n){

    if(n<=0)
        return 0;
    return (n%2==0?0:1) + countSetBit2(n/2);
}

int solve(int n){
    int ans = 0;

    for(int i=1;i<=n;i++){
        ans+=countSetBit2(i);
    }

    return ans;
}

int main(){

    for(int i=0;i<10;i++){
        cout<<i<<" "<<solve(i)<<endl;
    }
}
