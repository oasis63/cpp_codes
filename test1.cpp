#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

// find parent with path compression
int findParent(vector<int> &parent, int node) {
  if (parent[node] != node)
    parent[node] = findParent(parent, parent[node]);
  return parent[node];
}

// unite two nodes in a set
// node1 < node2  .. in value
void unite(vector<int> &parent, vector<int> &rank, int node1, int node2) {
  int root1 = findParent(parent, node1);
  int root2 = findParent(parent, node2);

  if (root1 == root2)
    return;

  if (rank[root1] < rank[root2]) {
    parent[root1] = root2;
  } else if (rank[root1] > rank[root2]) {
    parent[root2] = root1;
  } else {
    parent[root2] = root1;
    rank[root1]++;
  }
}

int main() {
  set_io_files("input.txt", "output.txt");

  int n, m;
  cin >> n >> m;
  cin.ignore();

  // union and find
  // 1...n
  // vector<int> parent(n + 1, -1);
  vector<int> parent(n + 1), rank(n + 1, 0);
  iota(parent.begin(), parent.end(), 0);

  int src, dest;
  for (int i = 0; i < m; i++) {
    cin >> src >> dest;
    cin.ignore();
    // bug(src, dest);
    // now unite the nodes

    unite(parent, rank, src, dest);
  }

  cout << "After updating parent vector \n";
  printVectorWithIndices(parent);

  vector<pair<int, int>> parentMapVect;

  for (int i = 1; i <= n; i++) {
    parentMapVect.push_back({i, findParent(parent, i)});
  }

  sort(parentMapVect.begin(), parentMapVect.end(), [](const auto &a, const auto &b) {
    return a.second < b.second;
  });

  cout << "\nParentMap : \n";
  printMap(parentMapVect);

  cout << "--------------------------------------\n";
  for (int i = 0; i <= n; i++) {
    cout << parentMapVect[i].first << "  " << parentMapVect[i].second << endl;
  }

  vector<pair<int, int>> ans;

  for (int i = 1; i <= n; i++) {
    int curr = parentMapVect[i].second;
    int prev = parentMapVect[i - 1].second;

    // bug(curr, prev);

    if (i > 0 && curr != 0 && curr != prev) {
      ans.push_back({prev, curr});
    }
  }

  cout << "\nAns------\n";

  int res_len = ans.size();
  cout << res_len << "\n";
  for (const auto &[u, v] : ans) {
    cout << u << " " << v << "\n";
  }

  return 0;
}