#include<bits/stdc++.h>
using namespace std;

bool usedInRow(vector<vector<char>> grid,int n,int row,char num){
    for(int col=0;col<n;col++){
        if(grid[row][col] == num)
            return true;
    }
    return false;
}

bool usedInCol(vector<vector<char>> grid,int n,int col,char num){

    for(int row=0;row<n;row++){
        if(grid[row][col] == num)
            return true;
    }
    return false;
}

/* Returns a boolean which indicates whether an assigned entry
within the specified 3x3 box matches the given number. */

bool usedInBox(vector<vector<char>> grid,int n,int boxStartRow,int boxStartCol,char num){

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
        }
    }
    return false;
}

bool isSafe(vector<vector<char>> grid,int n,int row,int col,char num){

    return !usedInRow(grid,n,row,num) && !usedInCol(grid,n,col,num) && !usedInBox(grid,n,row-row%3,col-col%3,num) && grid[row][col] == '.';
}


bool findUnassignedLocation(vector<vector<char>> grid,int n,int &row,int &col){

    for(row = 0;row<n;row++){
        for(col = 0;col<n;col++){
            if(grid[row][col] == '.')
                return true;
        }
    }
    return false;
}

bool solveSudokuUtil(vector<vector<char>> &grid,int n){
    int row,col;

    if(!findUnassignedLocation(grid,n,row,col))
        return true;

    for(char num='1';num<='9';num++){
        if(isSafe(grid,n,row,col,num)){

            grid[row][col] = num;

            if(solveSudokuUtil(grid,n))
                return true;

            grid[row][col] = '.';

        }
    }

    return false;
}

void solveSudoku(vector<vector<char> > &A) {
    int n = A.size();
    bool ret = solveSudokuUtil(A,n);

    cout<<ret<<endl;
}

void printGrid(vector<vector<char>> grid,int n){

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            cout<<grid[row][col]<<" ";
        }
        cout<<endl;
    }

}

int main(){

    vector<vector<char>> grid  {
                                    {'3', '.', '6', '5', '.', '8', '4', '.', '.'},
                                    {'5', '2', '.', '.', '.', '.', '.', '.', '.'},
                                    {'.', '8', '7', '.', '.', '.', '.', '3', '1'},
                                    {'.', '.', '3', '.', '1', '.', '.', '8', '.'},
                                    {'9', '.', '.', '8', '6', '3', '.', '.', '5'},
                                    {'.', '5', '.', '.', '9', '.', '6', '.', '.'},
                                    {'1', '3', '.', '.', '.', '.', '2', '5', '.'},
                                    {'.', '.', '.', '.', '.', '.', '.', '7', '4'},
                                    {'.', '.', '5', '2', '.', '6', '3', '.', '.'}
                                };

    int n = 9;

    solveSudoku(grid);
    printGrid(grid,n);

    return 0;

}
