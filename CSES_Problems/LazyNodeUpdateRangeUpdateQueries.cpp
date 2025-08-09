#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// segment tree with updating a range

typedef long long ll;

class SegmentTree {
 public:
  ll n;
  vector<ll> st;
  vector<ll> lazy;

  SegmentTree(ll _n) {
    this->n = _n;
    st.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
  }

  void buildUtil(ll start, ll ending, vector<ll> &vect, ll node) {
    if (start == ending) {
      st[node] = vect[start];
      return;
    }

    ll mid = (start + ending) / 2;

    buildUtil(start, mid, vect, 2 * node + 1);
    buildUtil(mid + 1, ending, vect, 2 * node + 2);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
  }

  void updateUtil(ll start, ll ending, ll l, ll r, ll val, ll node) {
    // non-overlapping case

    if (start > r || ending < l) {
      return;
    }

    // lazy propagation / clear the lazy upate .. update the previous lazy value
    if (lazy[node] != 0) {
      st[node] += lazy[node] * (ending - start + 1);

      if (start != ending) {
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
      }

      lazy[node] = 0;
    }

    // complete overlap
    if (start >= l && ending <= r) {
      st[node] += val * (ending - start + 1);
      if (start != ending) {
        lazy[2 * node + 1] += val;
        lazy[2 * node + 2] += val;
      }
      return;
    }

    // if (start == ending) {
    //   st[node] = val;
    //   return;
    // }

    ll mid = (start + ending) / 2;

    updateUtil(start, mid, l, r, val, 2 * node + 1);
    updateUtil(mid + 1, ending, l, r, val, 2 * node + 2);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
    return;
  }

  ll queryUtil(ll start, ll ending, ll l, ll r, ll node) {
    if (start > r || ending < l) {
      return 0;
    }

    // lazy propagation / clear the lazy update

    if (lazy[node] != 0) {
      st[node] += lazy[node] * (ending - start + 1);

      if (start != ending) {
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
      }

      lazy[node] = 0;
    }

    if (start >= l && ending <= r) {
      return st[node];
    }

    ll mid = (start + ending) / 2;

    ll q1 = queryUtil(start, mid, l, r, 2 * node + 1);
    ll q2 = queryUtil(mid + 1, ending, l, r, 2 * node + 2);

    return q1 + q2;
  }

  void build(vector<ll> &vect) {
    buildUtil(0, n - 1, vect, 0);
  }

  ll query(ll l, ll r) {
    return queryUtil(0, n - 1, l, r, 0);
  }

  void update(ll l, ll r, ll val) {
    updateUtil(0, n - 1, l, r, val, 0);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  ll n, q;
  cin >> n >> q;
  cin.ignore();

  vector<ll> nums(n, 0);

  for (ll &i : nums) {
    cin >> i;
  }

  SegmentTree tree(n);

  tree.build(nums);

  ll a, b, c, d;
  while (q--) {
    cin >> a;

    if (a == 2) {
      cin >> b;
      cin.ignore();
      ll res = tree.query(b - 1, b - 1);
      cout << res << endl;
    } else {
      cin >> b >> c >> d;
      cin.ignore();
      tree.update(b - 1, c - 1, d);
    }
  }

  return 0;
}

/*


Example
Input:

8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4
Output:

5
6


*/