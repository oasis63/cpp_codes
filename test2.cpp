#include <bits/stdc++.h>
using namespace std;

class Util {
  public:
    template <typename T> void printSet(const set<T> &s) {
        for (const auto &element : s) {
            cout << element;
        }
        cout << endl;
    }
    template <typename T> void printVector(const vector<T> &v) {
        for (const auto &element : v) {
            cout << element;
        }
        cout << endl;
    }
};
class Solution {
  public:
    int solve(vector<int> &nums) {
        Util util;
        int n = nums.size();
        int ans = 0;
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums{
        1,
        3,
        1,
    };
    cout << sol.solve(nums) << endl;
    return 0;
}
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();