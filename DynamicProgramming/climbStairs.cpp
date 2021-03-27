#include<bits/stdc++.h>
using namespace std;


int climbStairsSolution(int a) {
    
    int  n = a+1;
    int dp[n];
    memset(dp,0,sizeof(dp));

    // dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<n;i++){
        dp[i] = dp[i-2] + dp[i-1];
    }


    return dp[a];
}




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