#include<bits/stdc++.h>
using namespace std;


bool usedInRow(vector<vector<int>> grid,int n,int row,int num){
    for(int col=0;col<n;col++){
        if(grid[row][col] == num)
            return true;
    }
    return false;
}

bool usedInCol(vector<vector<int>> grid,int n,int col,int num){

    for(int row=0;row<n;row++){
        if(grid[row][col] == num)
            return true;
    }
    return false;
}

/* Returns a boolean which indicates whether an assigned entry
within the specified 3x3 box matches the given number. */

bool usedInBox(vector<vector<int>> grid,int n,int boxStartRow,int boxStartCol,int num){

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
        }
    }
    return false;
}

bool isSafe(vector<vector<int>> grid,int n,int row,int col,int num){

    return !usedInRow(grid,n,row,num) && !usedInCol(grid,n,col,num) && !usedInBox(grid,n,row-row%3,col-col%3,num) && grid[row][col] == 0;
}


bool findUnassignedLocation(vector<vector<int>> grid,int n,int &row,int &col){

    for(row = 0;row<n;row++){
        for(col = 0;col<n;col++){
            if(grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool solveSudoku(vector<vector<int>> &grid,int n){
    int row,col;

    if(!findUnassignedLocation(grid,n,row,col))
        return true;

    for(int num=1;num<=9;num++){
        if(isSafe(grid,n,row,col,num)){

            grid[row][col] = num;

            if(solveSudoku(grid,n))
                return true;

            grid[row][col] = 0;   // backtracking 

        }
    }

    return false;
}

void printGrid(vector<vector<int>> grid,int n){

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            cout<<grid[row][col]<<" ";
        }
        cout<<endl;
    }

}

int main(){

    vector<vector<int>> grid {

                    {3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0}
                };

    int n = 9;

    if(solveSudoku(grid,n) == true)
        printGrid(grid,n);
    else
        cout<<"No Solution Exists"<<endl;

    return 0;

}
