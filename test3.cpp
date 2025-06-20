#include <bits/stdc++.h>

using namespace std;

// since we are taking binary tree
// because of this we are using mid :
// diving the root(node) with two parts [ left tree , right tree]
vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
  sort(people.begin(), people.end(), [](auto &a, auto &b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
  });

  vector<vector<int>> result;
  for (vector<int> person : people) {
    result.insert(result.begin() + person[1], person);
  }

  return result;
}

int main() {
  vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};

  vector<vector<int>> ans = reconstructQueue(people);

  cout << "\nFinal Queue" << endl;
  for (vector<int> v : ans) {
    cout << v[0] << " " << v[1] << endl;
  }

  //   vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
  //   // cout << v.size();

  //   SegmentTree tree;

  //   tree.init(v.size());

  //   tree.build(v);

  //   cout << tree.query(0, 4) << '\n';

  //   tree.update(4, 10);

  //   cout << tree.query(2, 6) << '\n';

  //   tree.update(2, 20);

  //   cout << tree.query(0, 4) << '\n';

  return 0;
}