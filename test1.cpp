#include <bits/stdc++.h>
using namespace std;

class Util {
  public:
    template <typename T> void printSet(const set<T> &s) {
        for (const auto &element : s) {
            cout << element << " ";
        }
        cout << endl;
    }
    template <typename T> void printVector(const vector<T> &v) {
        for (const auto &element : v) {
            cout << element << " ";
        }
        cout << endl;
    }
};

class Solution {
  public:
    int solve(int n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= (n + 1); i++) {
            ans[i] = solve(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    Util util;

    int n = 5;

    vector<int> ans = sol.countBits(n);

    util.printVector(ans);

    return 0;
}
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
