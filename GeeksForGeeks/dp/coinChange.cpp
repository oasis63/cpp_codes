#include<bits/stdc++.h>
using namespace std;


// recursion solution for coin change 
// Two possibilities for a given coin
//  1) Solution which contains the coin
//  2) Solution which does not contain the coin 

// count the number of solutions for the given sum 
int recurCoinChange(int denos[],int n,int sum){

    if(sum == 0)
        return 1;
    if(sum<0)
        return 0;
    if(sum>=1 && n<=0)
        return 0;

    // don't add in the  solution :+:  add in a solution
    return recurCoinChange(denos,n-1,sum) + recurCoinChange(denos,n,sum-denos[n-1]);
}

int dynaCoinChange(int denos[],int n,int sum){

    int dp[sum+1][n];   // dp[sum][denos]

    for(int j=0;j<=n;j++){  
        dp[0][j] = 1;
    }
    

    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            // add to the solution
            int x = (i-denos[j] >= 0) ? dp[i-denos[j]][j] : 0;
            
            // do not add to the solution
            int y = (j>=1) ? dp[i][j-1]:0;
            dp[i][j] = x + y;
        }
    }


/*
    for(int i=0;i<=sum;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/


    return dp[sum][n-1];
}




int main(){
    
    int tc,n,sum;
    cin>>tc;
    while(tc--){
        cin>>n;
        int deons[n];
        for(int i=0;i<n;i++)
            cin>>deons[i];
        cin>>sum;
        cout<< dynaCoinChange(deons,n,sum)<<endl;
    }



    return 0;
}


/*

2
3
1 2 3
4
4
2 5 3 6
10


*/