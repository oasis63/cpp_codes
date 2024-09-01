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
    int solve(vector<int> &nums) {
        Util util;
        int n = nums.size();
        int ans = 0;
        return ans;
    }
};
int main() {
    Util util;
    Solution sol;

    string s(5, '0');

    s[3] = '4';

    cout << s << endl;

    const int i = s.find_first_not_of('0');

    cout << " i : " << i << endl;

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();