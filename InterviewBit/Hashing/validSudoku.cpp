#include <bits/stdc++.h>
using namespace std;

// Determine if a Sudoku is valid

bool usedInRow2(vector<vector<char>> grid, int n, int row, int col1, char num) {
    for (int col = 0; col < n; col++) {
        if (col != col1 && grid[row][col] == num)
            return true;
    }
    return false;
}

bool usedInCol2(vector<vector<char>> grid, int n, int row1, int col, char num) {
    for (int row = 0; row < n; row++) {
        if (row != row1 && grid[row][col] == num)
            return true;
    }
    return false;
}

/* Returns a boolean which indicates whether an assigned entry
within the specified 3x3 box matches the given number. */

bool usedInBox2(vector<vector<char>> grid, int n, int r, int c, char num) {
    int boxStartRow = r - r % 3;
    int boxStartCol = c - c % 3;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if ((row + boxStartRow) != r && (col + boxStartCol) != c &&
                grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
        }
    }
    return false;
}

bool isSafe2(vector<vector<char>> grid, int n, int row, int col, char num) {
    return !usedInRow2(grid, n, row, col, num) &&
           !usedInCol2(grid, n, row, col, num) &&
           !usedInBox2(grid, n, row, col, num);
}

bool isValidSudoku(vector<vector<char>> grid) {
    int n = grid.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '.')
                continue;
            if (isSafe2(grid, n, i, j, grid[i][j]) == false)
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> grid{{'3', '.', '6', '5', '.', '8', '4', '.', '.'},
                              {'5', '2', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '8', '7', '.', '.', '.', '.', '3', '1'},
                              {'.', '.', '3', '.', '1', '.', '.', '8', '.'},
                              {'9', '.', '.', '8', '6', '3', '.', '.', '5'},
                              {'.', '5', '.', '.', '9', '.', '6', '.', '.'},
                              {'1', '3', '.', '.', '.', '.', '2', '5', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '7', '4'},
                              {'.', '.', '5', '2', '.', '6', '3', '.', '.'}};

    int n = 9;

    bool v = isValidSudoku(grid);

    cout << "valid  : " << v << endl;

    return 0;
}
