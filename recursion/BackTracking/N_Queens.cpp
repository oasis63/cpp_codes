#include<bits/stdc++.h>
using namespace std;

/*
    N-Queens Problem ....
    using recursion and backtracking

    N queens to be placed in the N*N chess board such
    no queen  attacks  it
*/


bool is_attacked(vector<int> board[],int n,int x,int y){

    // checking in row x cels
    for(int i=0;i<n;i++){
        if(board[x][i]==1){
            return true;
        }
    }

    // checking in  column y
    for(int i=0;i<n;i++){
        if(board[i][y]==1){
            return true;
        }
    }

    // checking for diagonals
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)==(x+y)  && board[i][j]==1){
                return true;
            }
        }
    }

    // checking for diagonals
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i-j)==(x-y)  && board[i][j]==1){
                return true;
            }
        }
    }

    return false;
}

bool nQueens(vector<int>board[],int queens,int n){
    if(queens==0)
        return true;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(is_attacked(board,n,i,j)) // skip this cell
                continue;

            board[i][j] = 1;

            if(nQueens(board,queens-1,n))
                return true;

            board[i][j]=0; // if solution is not found .. undo changes
        }
    }
    return false;
}


void printVect(vector<int> board[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){

    int n = 4;

    vector<int> board[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i].push_back(0);
        }
    }

    int queens = n;

    if(nQueens(board,queens,n)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    printVect(board,n);
}

/*
    Because of backtracking and it checks all the possible cells where the
    queens can be placed
    1 does not start with the cell (0,0)
*/


/*

n

YES

0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


*/
