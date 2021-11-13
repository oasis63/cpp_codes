/* Finding the number of ways to reach from a starting
 position to an ending position travelling in specified 
 directions only.

  */

#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int min(int a,int b,int c){
    return min(a,min(b,c));
}

int numWays(int cost[R][C],int m,int n){


    int tc[m+1][n+1];

    tc[0][0] = 1;

    // set the costs for the first column
    for(int i= 1;i<=m;i++){
        tc[i][0] = 1;
    }

    // costs for the first row

    for(int j=1;j<=n;j++){
        tc[0][j]=1;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            tc[i][j] =tc[i-1][j]+tc[i][j-1];
        }

    }


    return tc[m][n];

}


int main(){

   int mat[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
  cout<<numWays(mat, 1,1)<<endl;
  cout<<numWays(mat, 2,2)<<endl;
   return 0;
}

