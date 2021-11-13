#include<bits/stdc++.h>
using namespace std;

#define N 3

//Path with maximum average value
// right or bottom


int solve(int arr[][N]){

    int dp[N][N];

    dp[0][0] = arr[0][0];

    // values for the first column 
    for(int i=0;i<N;i++){
        dp[i][0] = arr[i][0];
    }

    for(int i=0;i<N;i++){
        dp[0][i] = arr[0][i];
    }

    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]) + arr[i][j];
        }
    }

    return dp[N-1][N-1];
}



// Dynamic Program for finding the maximum path to reach [n][n] from [0][0]

double solve2(int arr[][N]){

    int path[N][N];

    path[0][0] = arr[0][0];

    // cost for the fist column
    for(int i=1;i<N;i++){
        path[i][0] = path[i-1][0] +  arr[i][0];
    }

    // cost for the fist row
    for(int i=1;i<N;i++){
        path[0][i] = path[0][i-1] +  arr[0][i];
    }


    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            path[i][j] = max(path[i][j-1],path[i-1][j]) + arr[i][j];
        }
    }

    //cout<< path[N-1][N-1]<<"\n\n"<<endl;


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }

    return (double)path[N-1][N-1]/(2*N-1);
}




int main(){

    int mat[][N] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                  };

    //cout<<"\n Maximum Path Value " << solve(mat,0,0)<<endl;

    cout<<"\n Maximum Path Value " << solve2(mat)<<endl;

}
