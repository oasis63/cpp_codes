#include <bits/stdc++.h>
using namespace std;

class SegementTree {
 public:
  int n;
  vector<int> st;

  SegementTree(int n) {
    this->n = n;
    st.resize(4 * n, 0);
  }

  void buildUtil(int start, int end, int node, vector<int>& vect) {
    if (start == end) {
      st[node] = vect[start];
      return;
    }

    int mid = (start + end) / 2;

    buildUtil(start, mid, 2 * node + 1, vect);
    buildUtil(mid + 1, end, 2 * node + 2, vect);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
  }

  void build(vector<int>& vect) {
    buildUtil(0, n - 1, 0, vect);
  }

  int queryUtil(int start, int end, int node, int l, int r) {
    if (start > r || end < l)
      return 0;
    if (start >= l && end <= r)
      return st[node];

    int mid = (start + end) / 2;

    int q1 = queryUtil(start, mid, 2 * node + 1, l, r);
    int q2 = queryUtil(mid + 1, end, 2 * node + 2, l, r);

    return q1 + q2;
  }

  void query(int l, int r) {
    return queryUtil(0, n - 1, 0, l, r);
  }

  void updateUtil(int start, int end, int node, int index, int value) {
    // base case
    if (start == ending) {
      st[node] = value;
      return;
    }

    int mid = (start + ending) / 2;
    if (index <= mid) {
      // left subtree
      updateUtil(start, mid, 2 * node + 1, index, value);
    } else {
      // right
      updateUtil(mid + 1, ending, 2 * node + 2, index, value);
    }

    st[node] = st[node * 2 + 1] + st[node * 2 + 2];

    return;
  }

  void update(int index, int value) {
    updateUtil(0, n - 1, 0, index, value);
  }
};

int main() {
  return 0;
}
