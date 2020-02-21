#include<bits/stdc++.h>
using namespace std;

 int stor[10000];

int climbStairs2(int n) {

    if(stor[n] == -1){
        if(n<=1)
            stor[n] = 1;
        else
            stor[n] = climbStairs2(n-1)+climbStairs2(n-2);

    }

    return stor[n];
}

int climbStairs(int n) {
    memset(stor,-1,sizeof(stor));
    return climbStairs2(n);
    
}

int main(){
    
    for(int i = 0;i<=10;i++){
        cout<<i<<"  "<<climbStairs(i)<<endl;
    }

    return 0;
}