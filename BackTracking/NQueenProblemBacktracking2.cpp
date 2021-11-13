//C++ program to solve N queen problem
// using backtracking

#include<bits/stdc++.h>
using namespace std;

#define N 5

void printSolution(int board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */

bool isSafe(int board[N][N],int row,int col){

    // row on left side
    for(int j=0;j<col;j++){
        if(board[row][j])
            return false;
    }

    // upper left diagonal
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j])
            return false;
    }

    // lower left diagonal
    for(int i=row,j=col;j>=0 && i<N;i++,j--){
        if(board[i][j])
            return false;
    }
    return true;
}

/*
Column is only passed ,, because in a column there can 
only be a single Queen present
*/

bool solveNQUtil(int board[N][N],int col){

    if(col >= N){
        return true;
    }

    for(int i=0;i<N;i++){

        if(isSafe(board,i,col)){

            board[i][col] = 1;

            if(solveNQUtil(board,col+1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;  // Queens cannot be placed in any row of this column
}

bool solveNQ(){

    int board[N][N]; //= {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    memset(board,0,sizeof(board));

    if(solveNQUtil(board,0) == false){
        cout<<"Solution doest not exist"<<endl;
        return false;
    }

    printSolution(board);
    return true;
}

int main(){

    solveNQ();

    return 0;
}

