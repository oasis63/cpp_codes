#include <bits/stdc++.h>

// #include "UTILS/helper.h"

using namespace std;

typedef long long ll;

class SegmentTree {
 public:
  ll n;
  vector<ll> st;

  SegmentTree(ll _n) {
    this->n = _n;
    st.resize(4 * n, 0);
  }

  void buildUtil(ll start, ll ending, ll node, vector<ll> &vect) {
    // leaf node
    if (start == ending) {
      st[node] = vect[start];
      return;
    }

    ll mid = (start + ending) / 2;

    // left sub tree
    buildUtil(start, mid, 2 * node + 1, vect);

    // right sub tree
    buildUtil(mid + 1, ending, 2 * node + 2, vect);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
  }

  ll queryUtil(ll start, ll ending, ll l, ll r, ll node) {
    // no overlapping
    if (start > r || ending < l) {
      return 0;
    }

    // complete overlapping
    if (start >= l && ending <= r) {
      return st[node];
    }

    //  partial case

    ll mid = (start + ending) / 2;

    ll q1 = queryUtil(start, mid, l, r, 2 * node + 1);
    ll q2 = queryUtil(mid + 1, ending, l, r, 2 * node + 2);

    return q1 + q2;
  }

  void updateUtil(ll start, ll ending, ll node, ll index, ll val) {
    if (start == ending) {
      st[node] = val;
      return;
    }

    int mid = (start + ending) / 2;

    if (index <= mid) {
      updateUtil(start, mid, 2 * node + 1, index, val);
    } else {
      updateUtil(mid + 1, ending, 2 * node + 2, index, val);
    }

    st[node] = st[2 * node + 1] + st[2 * node + 2];

    return;
  }

  void build(vector<ll> &vect) {
    ll n = vect.size();
    buildUtil(0, n - 1, 0, vect);
  }

  ll query(ll l, ll r) {
    return queryUtil(0, n - 1, l, r, 0);
  }

  void update(int index, int val) {
    updateUtil(0, n - 1, 0, index, val);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // set_io_files("input.txt", "output.txt");

  ll n, q;
  cin >> n >> q;
  cin.ignore();

  vector<ll> vect(n);

  for (ll &i : vect) {
    cin >> i;
  }
  cin.ignore();

  SegmentTree tree(n);

  tree.build(vect);

  ll a, b, c;

  while (q--) {
    cin >> a >> b >> c;
    cin.ignore();

    if (a == 1) {
      // update
      tree.update(b - 1, c);
    } else {
      ll res = tree.query(b - 1, c - 1);
      cout << res << endl;
    }
  }

  return 0;
}