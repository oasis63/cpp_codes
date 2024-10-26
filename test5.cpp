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
    int solve(vector<int> &nums) {

        int n = nums.size();
        int ans = 0;

        return ans;
    }
};

Solution sol;

bool canFormByRepeating(string &str, string &pattern) {

    if (str.length() % pattern.length() != 0) {
        return false;
    }

    string repeatedPattern = "";
    int repeatCount = str.length() / pattern.length();

    for (int i = 0; i < repeatCount; ++i) {
        repeatedPattern += pattern;
    }
    return repeatedPattern == str;
}

int main() {
    // vector<int> nums{1, 3, 1};
    // int res = sol.solve(nums);
    // cout << "res : " << res << endl;

    string str1 = "ABCABC";
    string str2 = "ABC";

    int n1 = str1.length();
    int n2 = str2.length();

    // string new_str = string(n2, str2[0]) * (n1 / n2);
    bool new_str = canFormByRepeating(str1, str2);

    cout << "new_str : " << new_str << endl;

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();