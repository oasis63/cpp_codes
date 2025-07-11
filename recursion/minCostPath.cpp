/* A Naive recursive implementation of MCP(Minimum Cost Path) problem */

#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int min(int a,int b,int c){
    return min(a,min(b,c));
}

int minCost(int cost[R][C],int m,int n){

    if(m<0 || n<0)
        return INT_MAX;
    else if(m==0 && n==0)
        return cost[m][n];
    else
        return cost[m][n]+min(minCost(cost,m-1,n),minCost(cost,m,n-1),minCost(cost,m-1,n-1));
}


int main(){

   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
  cout<<minCost(cost, 2, 1)<<endl;
   return 0;
}

