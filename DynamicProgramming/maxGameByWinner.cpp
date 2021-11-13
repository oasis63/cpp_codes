#include<bits/stdc++.h>
using namespace std;

//Maximum games played by winner

int maxGameByWinner(int n){

    int dp[n];
    dp[0]=1;   // 0 games === 1 player
    dp[1] = 2;  // 1 game === 2 player


    int i=2;

    do{
        dp[i] = dp[i-1] + dp[i-2];   //  1 2 3 5 8 13
    }while(dp[i++] <= n);

    return (i-2);

}


int main(){

    int n = 10;
    cout<<maxGameByWinner(n)<<endl;

    return 0;
}
