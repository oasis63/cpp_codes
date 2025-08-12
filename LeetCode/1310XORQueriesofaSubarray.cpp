
class SegmentTree {
 public:
  vector<int> st;
  int n;
  SegmentTree(int _n) {
    this->n = _n;
    st.resize(4 * _n, 0);
  }

  void buildUtil(int start, int ending, int node, vector<int>& v) {
    if (start == ending) {
      st[node] = v[start];
      return;
    }

    int mid = (start + ending) / 2;

    // left subtree
    buildUtil(start, mid, 2 * node + 1, v);

    // right subtree

    buildUtil(mid + 1, ending, 2 * node + 2, v);

    st[node] = st[2 * node + 1] ^ st[2 * node + 2];
  }

  void build(vector<int>& v) {
    buildUtil(0, n - 1, 0, v);
  }

  int queryUtil(int start, int ending, int l, int r, int node) {
    // non overlapping case
    if (start > r || ending < l) {
      return 0;
    }

    // complete overlap
    if (start >= l && ending <= r) {
      return st[node];
    }

    //  partial case

    int mid = (start + ending) / 2;

    int q1 = queryUtil(start, mid, l, r, 2 * node + 1);
    int q2 = queryUtil(mid + 1, ending, l, r, 2 * node + 2);

    return q1 ^ q2;
  }

  int query(int l, int r) {
    return queryUtil(0, n - 1, l, r, 0);
  }

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

    st[node] = st[2 * node + 1] ^ st[2 * node + 2];

    return;
  }

  void update(int x, int y) {
    updateUtil(0, n - 1, 0, x, y);
  }
};

class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = queries.size();

    int m = arr.size();
    // vector<int> ans(m, 0);

    vector<int> ans;
    vector<int> prefixXor(m + 1, 0);

    for (int i = 0; i < m; i++) {
      prefixXor[i + 1] = prefixXor[i] ^ arr[i];
    }

    for (int i = 0; i <= m; i++) {
      cout << "i : " << i << "  --> " << prefixXor[i] << endl;
    }

    // SegmentTree tree(m);
    // tree.build(arr);

    for (int i = 0; i < n; i++) {
      int l = queries[i][0];
      int r = queries[i][1];

      ans.push_back(prefixXor[r + 1] ^ prefixXor[l]);
    }
    return ans;
  }
};