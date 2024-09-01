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
    // vector<vector<int>> nums{{1, 4}, {0, 4}};
    vector<vector<int>> nums{{1, 4}, {2, 3}}; // [[1,4],[2,3]]

    sort(nums.begin(), nums.end(),
         [](const vector<int> &a, const vector<int> &b) {
             // Compare based on the first element
             if (a[0] != b[0]) {
                 return a[0] < b[0];
             } else {
                 // If the first elements are equal, compare based on the
                 // second element
                 return a[1] < b[1];
             }
         });

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();