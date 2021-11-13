#include<bits/stdc++.h>
using namespace std;

#define N 3

//Path with maximum average value
// right or bottom


int solve(int arr[][N],int i,int j){

    if(i>=N || j>=N)
        return 0;

    if(i==N-1  && j==N-1){
        return arr[i][j];
    }

    cout<<arr[i][j]<<endl;

    return arr[i][j] + max(solve(arr,i,j+1),solve(arr,i+1,j));
}



int main(){

    int mat[][N] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                  };

    cout<<"\n Maximum Path Value " << solve(mat,0,0)<<endl;
}
