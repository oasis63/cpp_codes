#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define uli unsigned long int

class Util {
  public:
    template <typename T> void printSet(const set<T> &s) {
        for (const auto &element : s) {
            cout << element << " ";
        }
        cout << endl;
    }
    template <typename T> void printVector(const vector<T> &v) {
        for (const auto &element : v) {
            cout << element << " ";
        }
        cout << endl;
    }
};

class Solution {
  public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + 1;
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[m - 1][n - 1];
    }

    nt uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        bool isPrevBlocked = obstacleGrid[0][0] == 1 ? true : false;
        if (isPrevBlocked)
            return 0;
        else
            obstacleGrid[0][0] = 1;

        for (int i = 1; i < n; i++) {
            if (isPrevBlocked) {
                obstacleGrid[i][0] = 0;
            } else {
                if (obstacleGrid[i][0] == 1) {
                    isPrevBlocked = true;
                    obstacleGrid[i][0] = 0;
                } else {
                    obstacleGrid[i][0] = 1;
                }
            }
        }

        isPrevBlocked = false;
        for (int j = 1; j < m; j++) {
            if (isPrevBlocked) {
                obstacleGrid[0][j] = 0;
            } else {
                if (obstacleGrid[0][j] == 1) {
                    isPrevBlocked = true;
                    obstacleGrid[0][j] = 0;
                } else {
                    obstacleGrid[0][j] = 1;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j])
                    obstacleGrid[i][j] = 0;
                else
                    obstacleGrid[i][j] =
                        obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }

        return obstacleGrid[n - 1][m - 1];
    }

    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 0 || n == 0)
            return 0;

        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main() {
    Util util;
    Solution sol;

    int m = 3;
    int n = 2;

    int ans = sol.uniquePaths(m, n);
    cout << "ans : " << ans << endl;

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
