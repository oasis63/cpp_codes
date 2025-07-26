#include <bits/stdc++.h>

// #include "UTILS/helper.h"
using namespace std;

// find parent of a node
int findParent(vector<int> &parent, int node) {
  if (parent[node] == node) {
    return node;
  }
  return findParent(parent, parent[node]);
}

// unite two nodes in a set
// node1 < node2  .. in value
void unite(vector<int> &parent, int node1, int node2) {
  int node1Parent = findParent(parent, node1);
  int node2Parent = findParent(parent, node2);

  parent[node2Parent] = node1Parent;
}

int main() {
  // set_io_files("input.txt", "output.txt");

  int n, m;
  cin >> n >> m;
  cin.ignore();

  // vector<pair<int,int>> edges;
  unordered_map<int, int> edges;
  int src, dest;

  for (int i = 0; i < m; i++) {
    cin >> src >> dest;
    cin.ignore();

    edges[src] = dest;
  }

  // union and find
  // 0....n-1
  // 1...n
  vector<int> parent(n + 1, -1);
  // cout << "n : " << n << endl;
  // cout << "parent size : " << parent.size() << endl;
  // same node will be parent of itself initially

  // unordered_map<int, int> parentMap;

  for (int i = 0; i <= n; i++) {
    parent[i] = i;
    // parentMap[i] = i;
  }

  // cout << "initial parent vector \n";
  // printVectorWithIndices(parent);

  // now unite the nodes having
  for (const auto &[node1, node2] : edges) {
    unite(parent, node1, node2);
  }

  // cout << "After updating parent vector \n";
  // printVectorWithIndices(parent);

  // cout << "\nNow find out the values not matching : " << "\n";

  vector<pair<int, int>> ans;
  // int prev_index;

  for (int i = 1; i <= n; i++) {
    if (i > 1 && parent[i] != parent[i - 1]) {
      ans.push_back({i - 1, i});
      // parent[i] = parent[i - 1];
    }
    // if (i == 1) {
    //   prev_index = i;
    // } else if (parent[i] != parent[prev_index]) {
    //   ans.push_back({prev_index, i});
    //   parent[i] = parent[prev_index];
    //   prev_index = i;
    // }
  }

  // cout << "Again after updating the parent \n";
  // printVectorWithIndices(parent);

  // cout << "\nAns Pair \n";
  // printPairVect(ans);

  int res_len = ans.size();
  cout << res_len << "\n";
  for (const auto &[u, v] : ans) {
    cout << u << " " << v << "\n";
  }

  return 0;
}