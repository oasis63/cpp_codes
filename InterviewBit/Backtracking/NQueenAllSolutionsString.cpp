#include<bits/stdc++.h>
using namespace std;

/*
Printing all solutions in N-Queen Problem
*/

void print(vector<string> board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].length();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(vector<string> board,int n,int row,int col){

    // checking in row x cells
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }

    // checking in  column y
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }

    // checking for diagonals
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)==(row+col)  && board[i][j]=='Q'){
                return false;
            }
        }
    }

    // checking for diagonals
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i-j)==(row-col)  && board[i][j]=='Q'){
                return false;
            }
        }
    }

    return true;
}


bool NQueensUtil(int q,int col,vector<string> &board,vector<vector<string>> &ans){

    if( col >= q){
        //print(board);
        ans.push_back(board);
        return true;
    }

    bool res = false;
    for(int i=0;i<q;i++){
        if(isSafe(board,q,i,col)){
            board[i][col] = 'Q';

            res = NQueensUtil(q,col+1,board,ans) || res;

            board[i][col]='.';
        }
    }

    return res;
}


vector<vector<string>> solveNQueens(int q) {

    vector<string> board(q);
    vector<vector<string>> ans;

    for(int i=0;i<q;i++){
        for(int j=0;j<q;j++){
            board[i].push_back('.');
        }
    }
    int current = 0;

    /*if(NQueensUtil(q,0,board,ans) == false){
        cout<<"Solution doest not exist"<<endl;
    }*/

    NQueensUtil(q,0,board,ans);
    return ans;
}


int main(){

    int q = 5;
    vector<vector<string>> ans = solveNQueens(q);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }

    return 0;
}
