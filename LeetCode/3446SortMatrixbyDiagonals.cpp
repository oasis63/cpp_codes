#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution1 {
 public:
  vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    // cout << "bottom-left triangle \n";

    for (int i = 0; i < n; i++) {
      int row = i, col = 0;

      vector<int> temp;

      while (row < n && col < n) {
        // cout << grid[row][col] << " ";
        temp.push_back(grid[row][col]);

        row++;
        col++;
      }

      sort(temp.rbegin(), temp.rend());

      row = i, col = 0;
      int ind = 0;
      // int temp_len = temp.size();

      while (row < n && col < n) {
        // cout << grid[row][col] << " ";
        temp.push_back(grid[row][col]);

        grid[row][col] = temp[ind];

        ind++;
        row++;
        col++;
      }
    }

    // cout << "top-right triangle \n";

    for (int j = 1; j < n; j++) {
      // for (int j = i; j < n; j++) {
      //   cout << grid[i][j] << " ";
      // }

      int row = 0, col = j;
      vector<int> temp;

      while (row < n && col < n) {
        // cout << grid[row][col] << " ";
        temp.push_back(grid[row][col]);

        row++;
        col++;
      }

      sort(temp.begin(), temp.end());

      row = 0, col = j;
      int ind = 0;
      // int temp_len = temp.size();

      while (row < n && col < n) {
        // cout << grid[row][col] << " ";
        temp.push_back(grid[row][col]);

        grid[row][col] = temp[ind];

        ind++;
        row++;
        col++;
      }
    }

    return grid;
  }
};

class Solution {
 public:
  vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    map<int, vector<int>> mp;
    int n = grid.size();

    // take out the values from (i,j) cell and
    // put it inside [i-j] map key's vector
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        mp[i - j].push_back(grid[i][j]);
      }
    }

    // for (auto& [key, vect] : mp) {
    //   cout << "key : " << key << " :  \t";
    //   for (int& el : vect) {
    //     cout << el << "  ";
    //   }
    //   cout << endl;
    // }

    for (auto& [key, vect] : mp) {
      if (key < 0) {
        sort(vect.rbegin(), vect.rend());
      } else {
        sort(vect.begin(), vect.end());
      }
    }

    // cout << "Ater sorting \n";

    // for (auto& [key, vect] : mp) {
    //   cout << "key : " << key << " :  \t";
    //   for (int& el : vect) {
    //     cout << el << "  ";
    //   }
    //   cout << endl;
    // }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        grid[i][j] = mp[i - j].back();
        mp[i - j].pop_back();
      }
    }

    return grid;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line;
  getline(cin, line);

  vector<vector<int>> grid = parse2DVector<int>(line);

  print2DVector(grid);

  cout << "Solution started ...." << endl;
  vector<vector<int>> ans = sol.sortMatrix(grid);

  cout << "=======================\n";

  print2DVector(ans);

  return 0;
}