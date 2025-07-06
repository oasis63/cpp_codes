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

    template <typename T> void print2DVector(const vector<vector<T>> &vec) {
        for (const auto &row : vec) {
            for (const auto &element : row) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

Util util;

// task is to find the number of ways to reach from start to destination

class Solution {
  public:
    int solveUtil(vector<vector<int>> &adj, int curr, int src, int dest,
                  vector<bool> &visited) {

        if (curr == dest) {
            return 1;
        }

        int nCurr = curr == -1 ? src : curr;

        visited[nCurr] = true;
        int ans = 0;

        for (int val : adj[nCurr]) {
            if (!visited[val]) {
                ans += solveUtil(adj, val, src, dest, visited);
            }
        }

        visited[nCurr] = false;
        return ans;
    }

    int possible_paths(vector<vector<int>> edges, int n, int src, int dest) {
        vector<vector<int>> adj(n);

        for (const auto pr : edges) {
            adj[pr[0]].push_back(pr[1]);
        }

        vector<bool> visited(n, false);

        return solveUtil(adj, src, src, dest, visited);
        ;
    }
};

Solution sol;

int main() {

    vector<vector<int>> edges = {{0, 1}, {0, 3}, {0, 2},
                                 {2, 0}, {2, 1}, {1, 3}};
    int n = 4;
    int start = 0;
    int destination = 3;

    int res = sol.possible_paths(edges, n, start, destination);

    cout << "\n res : " << res << endl;

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();