#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
 public:
  vector<long long> st;  // max value in range
  int n;
  const long long NEG_INF = -1e15;

  SegmentTree(vector<int>& v) {
    n = v.size();
    st.resize(4 * n, NEG_INF);
    build(0, n - 1, 0, v);
  }

  void build(int start, int end, int node, vector<int>& v) {
    if (start == end) {
      st[node] = v[start];
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * node + 1, v);
    build(mid + 1, end, 2 * node + 2, v);
    st[node] = max(st[2 * node + 1], st[2 * node + 2]);
  }

  void update(int start, int end, int node, int idx, long long val) {
    if (start == end) {
      st[node] = val;
      return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
      update(start, mid, 2 * node + 1, idx, val);
    else
      update(mid + 1, end, 2 * node + 2, idx, val);

    st[node] = max(st[2 * node + 1], st[2 * node + 2]);
  }

  void update(int idx, long long val) {
    update(0, n - 1, 0, idx, val);
  }

  // queryUtil
  int findFirst(int start, int end, int node, long long fruit) {
    if (st[node] < fruit)
      return -1;  // no basket fits in this segment

    if (start == end) {
      return start;  // found leaf index
    }

    int mid = (start + end) / 2;
    int leftAns = findFirst(start, mid, 2 * node + 1, fruit);
    if (leftAns != -1)
      return leftAns;
    return findFirst(mid + 1, end, 2 * node + 2, fruit);
  }

  // query
  int findFirst(long long fruit) {
    return findFirst(0, n - 1, 0, fruit);
  }
};

class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    int ans = 0;

    SegmentTree tree(baskets);

    for (int fruit : fruits) {
      int idx = tree.findFirst(fruit);
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
