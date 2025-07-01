#include <bits/stdc++.h>
using namespace std;

class DSU {
 public:
  vector<int> parent;
  DSU(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  bool unite(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return false;
    parent[yr] = xr;
    return true;
  }
};