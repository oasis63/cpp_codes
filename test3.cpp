#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class SegmentTree {
 public:
  vector<int> st;   // stores index of smallest element >= fruit in the segment
  vector<int> arr;  // original array
  int n;
  const int INF = 1e9;

  SegmentTree(vector<int>& v) {
    n = v.size();
    arr = v;
    st.resize(4 * n, INF);
    build(0, n - 1, 0);
  }

  void build(int start, int end, int node) {
    if (start == end) {
      st[node] = start;  // store index
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * node + 1);
    build(mid + 1, end, 2 * node + 2);
    st[node] = min(st[2 * node + 1], st[2 * node + 2]);  // min index
  }

  // Update value at position idx
  void update(int start, int end, int node, int idx, int val) {
    if (start == end) {
      arr[idx] = val;
      st[node] = idx;
      return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
      update(start, mid, 2 * node + 1, idx, val);
    else
      update(mid + 1, end, 2 * node + 2, idx, val);

    st[node] = min(st[2 * node + 1], st[2 * node + 2]);
  }

  void update(int idx, int val) {
    update(0, n - 1, 0, idx, val);
  }

  // Find smallest index where arr[index] >= fruit
  int findFirst(int start, int end, int node, int fruit) {
    if (start == end) {
      return (arr[start] >= fruit) ? start : INF;
    }

    int mid = (start + end) / 2;
    // Check left child first
    if (arr[st[2 * node + 1]] >= fruit) {
      return findFirst(start, mid, 2 * node + 1, fruit);
    }
    return findFirst(mid + 1, end, 2 * node + 2, fruit);
  }

  int findFirst(int fruit) {
    int idx = findFirst(0, n - 1, 0, fruit);
    return (idx == INF ? -1 : idx);
  }
};

class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    int ans = 0;

    vector<int> placed(n, -1);

    int m = baskets.size();

    vector<pair<int, int>> basket_pair;

    for (int i = 0; i < m; i++) {
      basket_pair.emplace_back(baskets[i], i);
    }

    sort(basket_pair.begin(), basket_pair.end());

    SegmentTree tree(baskets);

    for (int i = 0; i < n; i++) {
      int fruit = fruits[i];

      int p_ind = tree.findFirst(fruit);

      bug(fruit, p_ind);

      // int value = basket_pair[p_ind].first;
      // int ind = basket_pair[p_ind].second;

      // bug(fruit, value, ind);
    }

    for (int i : fruits) {
      if (i != -1) {
        ans++;
      }
    }

    // for (int i = 0; i < n; i++) {
    //   int fruit = fruits[i];

    //   int p_ind = lower_bound(basket_pair.begin(), basket_pair.end(), make_pair(fruit, -1),
    //                           [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; }) -
    //               basket_pair.begin();

    //   int value = basket_pair[p_ind].first;
    //   int ind = basket_pair[p_ind].second;

    //   bug(fruit, value, ind);
    // }

    // printPairVect(basket_pair);

    // for (int i = 0; i < n; i++) {
    //   bool found = false;
    //   // for (auto it = available.begin(); it != available.end(); ++it) {
    //   for (int j = 0; j < m; j++) {
    //     if (baskets[j] >= fruits[i]) {
    //       baskets[j] = -1;
    //       found = true;
    //       break;
    //     }
    //   }

    //   if (found) {
    //     fruits[i] = -1;
    //   }
    // }

    // for (int i : fruits) {
    //   if (i != -1) {
    //     ans++;
    //   }
    // }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line;
  getline(cin, line);

  vector<int> fruits = parseVector<int>(line);
  getline(cin, line);

  vector<int> baskets = parseVector<int>(line);

  cout << "Solution started ...." << endl;
  int ans = sol.numOfUnplacedFruits(fruits, baskets);

  cout << "ans : " << ans << endl;

  return 0;
}