#include <bits/stdc++.h>

#include "UTILS/helper.h"
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

  // bug(node1, node1Parent, node2, node2Parent);

  if (node1Parent < node2Parent)
    parent[node2Parent] = node1Parent;
  else
    parent[node1Parent] = node2Parent;
}

int main() {
  set_io_files("input.txt", "output.txt");

  int n, m;
  cin >> n >> m;
  cin.ignore();

  // union and find
  // 1...n
  vector<int> parent(n + 1, -1);

  for (int i = 0; i <= n; i++) {
    parent[i] = i;
  }

  int src, dest;

  for (int i = 0; i < m; i++) {
    cin >> src >> dest;
    cin.ignore();
    // bug(src, dest);
    // now unite the nodes

    unite(parent, src, dest);
  }

  // cout << "initial parent vector \n";
  // printVectorWithIndices(parent);

  cout << "After updating parent vector \n";
  printVectorWithIndices(parent);

  vector<pair<int, int>> parentMapVect;

  for (int i = 1; i <= n; i++) {
    parentMapVect.push_back({i, parent[i]});
  }

  sort(parentMapVect.begin(), parentMapVect.end(), [](const auto &a, const auto &b) {
    return a.second < b.second;
  });

  cout << "\nParentMap : \n";
  printMap(parentMapVect);

  return 0;
}