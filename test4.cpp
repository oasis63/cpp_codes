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
    vector<int> monotonicIncreasing(vector<int> nums) {
        vector<int> result;
        stack<int> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > nums[i]) {
                st.pop();
            }
            st.push(nums[i]);
        }

        while (!st.empty()) {
            result.insert(result.begin(), st.top());
            st.pop();
        }

        return result;
    }

    int nextGreater(vector<int> &vect, int j, int val) {
        for (; j < vect.size(); j++) {
            if (vect[j] > val)
                return vect[j];
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        for (int el : nums1) {
            int ind = find(nums2.begin(), nums2.end(), el) - nums2.begin();
            res.push_back(nextGreater(nums2, ind, el));
        }
        return res;
    }
};

Solution sol;

int main() {

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> res = sol.nextGreaterElement(nums1, nums2);

    cout << endl;
    for (int el : res) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();