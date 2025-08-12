#include <bits/stdc++.h>

// #include "UTILS/helper.h"
using namespace std;

class SegmentTree {
 public:
  int n;
  vector<int> st;

  SegmentTree(int _n) {
    this->n = _n;
    st.resize(4 * n, 0);
  }

  void buildUtil(int start, int ending, vector<int> &vect, int node) {
    if (start == ending) {
      st[node] = vect[start];
      return;
    }

    int mid = (start + ending) / 2;

    buildUtil(start, mid, vect, 2 * node + 1);
    buildUtil(mid + 1, ending, vect, 2 * node + 2);

    st[node] = min(st[2 * node + 1], st[2 * node + 2]);
  }

  void build(vector<int> &vect) {
    buildUtil(0, n - 1, vect, 0);
  }

  int queryUtil(int start, int ending, int l, int r, int node) {
    if (start > r || ending < l) {
      return INT_MAX;
    }

    if (start >= l && ending <= r) {
      return st[node];
    }

    int mid = (start + ending) / 2;

    int q1 = queryUtil(start, mid, l, r, 2 * node + 1);
    int q2 = queryUtil(mid + 1, ending, l, r, 2 * node + 2);

    return min(q1, q2);
  }

  int query(int l, int r) {
    return queryUtil(0, n - 1, l, r, 0);
  }

  void updateUtil(int start, int ending, int index, int val, int node) {
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

    st[node] = min(st[2 * node + 1], st[2 * node + 2]);

    return;
  }

  void update(int index, int val) {
    updateUtil(0, n - 1, index, val, 0);
  }
};

int main() {
  // set_io_files("input.txt", "output.txt");

  int n, q;
  cin >> n >> q;
  cin.ignore();

  vector<int> vect(n, 0);

  for (int &i : vect) {
    cin >> i;
  }

  SegmentTree tree(n);
  tree.build(vect);

  int a, b, c;

  while (q--) {
    cin >> a >> b >> c;
    cin.ignore();
    if (a == 1) {
      tree.update(b - 1, c);
    } else {
      int res = tree.query(b - 1, c - 1);
      cout << res << endl;
    }
  }

  return 0;
}