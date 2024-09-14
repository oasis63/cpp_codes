#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define uli unsigned long int

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

    template <typename T> void print2DVector(const vector<vector<T>> &vec) {
        for (const auto &row : vec) {
            for (const auto &element : row) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

Util util;
class Solution {
  public:
    int longestSubarray(vector<int> &nums) {
        int n = nums.size();

        auto maxIt = max_element(nums.begin(), nums.end());
        int maxIndex = distance(nums.begin(), maxIt);

        int resLen = 0;
        int bitAnd = 1;
        int ans = 1;

        for (int i = maxIndex; i < n; i++) {
            cout << "nums[i] " << nums[i] << "  ";
            int tempAnd = bitAnd & nums[i];

            cout << "tempAnd : " << tempAnd << endl;

            if (tempAnd >= bitAnd) {
                resLen++;
                ans = max(ans, resLen);
            } else {
                resLen = 1;
                bitAnd = nums[i];
            }
        }
        return ans;
    }
};
Solution sol;

int main() {

    vector<int> nums{1, 2, 3, 3, 2, 2};
    int res = sol.longestSubarray(nums);
    cout << "res : " << res << endl;

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();