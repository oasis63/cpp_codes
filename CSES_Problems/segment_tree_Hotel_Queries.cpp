#include <bits/stdc++.h>

// #include "UTILS/helper.h"

using namespace std;

typedef long long ll;

class SegmentTree {
 public:
  int n;
  // this tree will contain max value in a range
  vector<ll> st;
  const ll NEG_INF = INT_MIN;

  SegmentTree(int _n) {
    this->n = _n;
    st.resize(4 * n, NEG_INF);
  }

  // build
  void buildUtil(int start, int ending, int node, vector<int>& vect) {
    if (start == ending) {
      // bug(node, start);
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

vector<int> hotelQueries(vector<int>& hotels, vector<int>& groups) {
  int n = hotels.size();
  int m = groups.size();

  SegmentTree tree(n);
  tree.build(hotels);

  vector<int> ans;

  for (int i = 0; i < m; i++) {
    int grp = groups[i];

    int ind = tree.queryFindFirst(grp);

    if (ind != -1) {
      hotels[ind] -= grp;
      tree.update(ind, hotels[ind]);
      // tree.update(ind, hotels[ind] - grp); // this is not working
    }

    ans.push_back(ind + 1);
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // set_io_files("input.txt", "output.txt");

  int n, m;
  cin >> n >> m;
  cin.ignore();

  vector<int> hotels(n);
  vector<int> groups(m);

  for (int& i : hotels) {
    cin >> i;
  }

  cin.ignore();

  for (int& i : groups) {
    cin >> i;
  }

  vector<int> ans = hotelQueries(hotels, groups);

  for (int& a : ans) {
    cout << a << " ";
  }
  cout << "\n";

  return 0;
}
