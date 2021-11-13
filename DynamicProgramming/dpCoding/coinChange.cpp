#include<bits/stdc++.h>
using namespace std;

// Recursive Coin Change Solution 

int recCoinChange(int arr[],int m,int n){

    if(n<0)
        return 0;
    if(n==0)
        return 1;

    if(m<=0 && n>=1)
        return 0;

    return recCoinChange(arr,m-1,n)+recCoinChange(arr,m,n-arr[m-1]);

}

int dynaWays(int arr[],int m,int n){

    int dp[n+1][m];

    int x,y;

    for(int i=0;i<=n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=0;
        }
    }

    // when n is 0 ....
    for(int j=0;j<m;j++){
        dp[0][j]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            
            x = (i-arr[j] >= 0) ? dp[i-arr[j]][j]:0;
            y=(j>=1)?dp[i][j-1]:0;

            dp[i][j]=x+y;

        }
    }

    return dp[n][m-1];
}


int main(){
        
    int m = 3;
    int n= 4;
    int arr[] = {1,2,3};
    
    cout<<recCoinChange(arr,m,n)<<endl;

    return 0;
}