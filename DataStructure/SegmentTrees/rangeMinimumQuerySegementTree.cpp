#include <bits/stdc++.h>
using namespace std;


// Range Minimum Queries


class SegmentTree {
public:
  vector<int> st;
  int n;
  SegmentTree(int _n) {
    this->n = _n;
    st.resize(4 * _n, 0);
  }

  void printVect() {
    cout << "-------------------" << endl;

    for (int i : st) {
      cout << i << "  ";
    }
    cout << "\n-------------------" << endl;
  }

  void buildUtil(int start, int ending, int node, vector<int> &v) {
    if (start == ending) {
      st[node] = v[start];
      return;
    }

    int mid = (start + ending) / 2;

    // left subtree
    buildUtil(start, mid, 2 * node + 1, v);

    // right subtree

    buildUtil(mid + 1, ending, 2 * node + 2, v);

    st[node] = min(st[2 * node + 1], st[2 * node + 2]);
  }

  void build(vector<int> &v) {
    buildUtil(0, n - 1, 0, v);
    printVect();
  }

  int queryUtil(int start, int ending, int l, int r, int node) {
    // non overlapping case
    if (start > r || ending < l) {
      return INT_MAX;
    }

    // complete overlap
    if (start >= l && ending <= r) {
      return st[node];
    }

    //  partial case

    int mid = (start + ending) / 2;

    int q1 = queryUtil(start, mid, l, r, 2 * node + 1);
    int q2 = queryUtil(mid + 1, ending, l, r, 2 * node + 2);

    return min(q1, q2);
  }

  int query(int l, int r) { return queryUtil(0, n - 1, l, r, 0); }

  void updateUtil(int start, int ending, int node, int index, int value) {
    if (start == ending) {
      st[node] = value;
      return;
    }

    int mid = (start + ending) / 2;

    // left
    if (index <= mid) {
      updateUtil(start, mid, 2 * node + 1, index, value);
    } else {
      updateUtil(mid + 1, ending, 2 * node + 2, index, value);
    }

    st[node] = min(st[2 * node + 1], st[2 * node + 2]);

    return;
  }

  void update(int x, int y) { updateUtil(0, n - 1, 0, x, y); }
};

int main() {

  cout << "Segment Tree" << endl;

  vector<int> v = {3, 2, 4, 5, 1, 1, 5, 3};
  // cout << v.size();

  SegmentTree tree(v.size());

  cout << "tree size1 : " << tree.n << endl;

  cout << "st size : " << tree.st.size() << endl;

  // tree.init(v.size());

  tree.build(v);

  cout << tree.query(0, 3) << '\n';

  cout << tree.query(4, 5) << '\n';

  tree.update(1, 3);

  cout << tree.query(0, 3) << '\n';

  // tree.update(2, 20);

  // cout << tree.query(0, 4) << '\n';

  return 0;
}

/*

n = 8 , arr =[3, 2, 4, 5, 1, 1, 5, 3]
queries = [
    [2, 1, 4],
    [2, 5, 6],
    [1, 2, 3],
    [2, 1, 4]

  [2, 1, 3]


 1. update the value at position k to u

 2.  what is the minimum value in range [a,b]?


*/