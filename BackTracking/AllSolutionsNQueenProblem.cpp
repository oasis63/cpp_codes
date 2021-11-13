#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(vector<vector<int>> board,int n,int row,int col){

    // checking in row x cells
    for(int i=0;i<n;i++){
        if(board[row][i]==1){
            return false;
        }
    }

    // checking in  column y
    for(int i=0;i<n;i++){
        if(board[i][col]==1){
            return false;
        }
    }

    // checking for diagonals
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)==(row+col)  && board[i][j]==1){
                return false;
            }
        }
    }

    // checking for diagonals
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i-j)==(row-col)  && board[i][j]==1){
                return false;
            }
        }
    }

    return true;
}


bool NQueensUtil(int q,int col,vector<vector<int>> &board){

    if( col >= q){
        print(board);
        return true;
    }

    bool res = false;
    for(int i=0;i<q;i++){
        if(isSafe(board,q,i,col)){
            board[i][col] = 1;

            res = NQueensUtil(q,col+1,board) || res;

            board[i][col]=0;
        }
    }

    return res;
}


vector<vector<int> > solveNQueens(int q) {

    vector<vector<int>> board(q);
    for(int i=0;i<q;i++){
        for(int j=0;j<q;j++){
            board[i].push_back(0);
        }
    }
    int current = 0;
    if(NQueensUtil(q,0,board) == false){
        cout<<"Solution doest not exist"<<endl;
    }
    return board;
}


int main(){

    int q = 4;
    vector<vector<int>> ans = solveNQueens(q);

    return 0;
}
