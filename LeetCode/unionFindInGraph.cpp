#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// 1971. Find if Path Exists in Graph

class UnionFind {
 public:
  vector<int> parent;
  vector<int> rank;

  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);

    for (int i = 0; i < n; i++) {
      this->parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
      } else {
        parent[rootY] = rootX;
        rank[rootX]++;
      }
    }
  }

  bool isConnected(int x, int y) {
    return find(x) == find(y);
  }
};

class Solution {
 public:
  bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
    UnionFind uf(n);

    for (auto& e : edges) {
      int src = e[0];
      int dest = e[1];

      uf.unionSet(src, dest);
    }

    return uf.isConnected(src, dest);
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

  vector<int> nums = parseVector<int>(line);

  printVect(nums);

  cout << "Solution started ...." << endl;
  int ans = sol.solve(nums);

  cout << "ans : " << ans << endl;

  return 0;
}