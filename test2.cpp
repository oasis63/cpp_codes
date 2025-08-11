#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

typedef long long ll;

class SegmentTree {
 public:
  int n;
  // this tree will contain max value in a range
  vector<ll> st;
  // const ll NEG_INF = INT_MIN;
  const ll NEG_INF = -1e15;

  SegmentTree(int _n) {
    this->n = _n;
    st.resize(4 * n, NEG_INF);
  }

  // build
  void buildUtil(int start, int ending, int node, vector<int>& vect) {
    if (start == ending) {
      st[node] = vect[start];
      return;
    }

    int mid = (start + ending) / 2;

    buildUtil(start, mid, 2 * node + 1, vect);
    buildUtil(mid + 1, ending, 2 * node + 2, vect);

    st[node] = max(st[2 * node + 1], st[2 * node + 2]);
  }

  void build(vector<int>& vect) {
    buildUtil(0, n - 1, 0, vect);
  }

  // update

  void updateUtil(int start, int ending, int index, ll val, int node) {
    if (start == ending) {
      st[node] = val;
      return;
    }

    int mid = (start + ending) / 2;
    if (index <= mid) {
      updateUtil(start, mid, index, val, 2 * node + 1);
    } else {
      updateUtil(mid + 1, ending, index, val, 2 * node + 2);
    }

    st[node] = max(st[2 * node + 1], st[2 * node + 2]);
  }

  void update(int index, ll val) {
    updateUtil(0, n - 1, index, val, 0);
  }

  // query
  // return a index in from st
  // such that it is greater than value val
  int queryFindFirstUtil(int start, int ending, int node, int val) {
    if (st[node] < val)
      return -1;

    if (start == ending) {
      return start;
    }

    int mid = (start + ending) / 2;

    int leftTree = queryFindFirstUtil(start, mid, 2 * node + 1, val);

    if (leftTree != -1)
      return leftTree;

    int rightTree = queryFindFirstUtil(mid + 1, ending, 2 * node + 2, val);

    return rightTree;
  }

  int queryFindFirst(ll val) {
    return queryFindFirstUtil(0, n - 1, 0, val);
  }
};

class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    int ans = 0;

    SegmentTree tree(n);
    tree.build(baskets);

    for (int fruit : fruits) {
      int idx = tree.queryFindFirst(fruit);
      if (idx == -1) {
        ans++;
      } else {
        tree.update(idx, -1e15);
      }
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> fruits1 = {4, 2, 5};
  vector<int> baskets1 = {3, 5, 4};
  Solution sol;
  cout << sol.numOfUnplacedFruits(fruits1, baskets1) << "\n";  // Expected: 1

  vector<int> fruits2 = {3, 6, 1};
  vector<int> baskets2 = {6, 4, 7};
  cout << sol.numOfUnplacedFruits(fruits2, baskets2) << "\n";  // Expected: 0

  return 0;
}
