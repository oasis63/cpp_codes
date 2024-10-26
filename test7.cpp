#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define uli unsigned long int

class Util {
  public:
    template <typename T> void printSet(const set<T> &s) {
        cout << endl;
        for (const auto &element : s) {
            cout << element << " ";
        }
        cout << endl;
    }
    template <typename T> void printVector(const vector<T> &v) {
        cout << endl;
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
    int nextGreater(vector<int> &vect, int j, int val) {
        int n = vect.size();
        int k = (j + 1) % n;
        while (k != j) {
            if (vect[k] > val)
                return vect[k];
            k = (k + 1) % n;
        }
        return -1;
    }

    vector<int> nextGreaterElements(vector<int> &nums) {

        int n1 = nums.size();

        vector<bool> visited(n1, false);

        nums.insert(nums.end(), nums.begin(), nums.end());

        vector<int> res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;

        stack<pair<int, int>> st; // value , index
        st.push({nums[0], 0});

        unordered_map<int, int> mp;

        for (int i = 1; i < n; i++) {
            // monotonic decreasing
            cout << " current element : " << nums[i] << endl;
            while (!st.empty() && nums[i] > st.top().first) {
                cout << "inside while" << endl;
                // if(mp[st.top])
                // if(mp[st.top()])
                mp[st.top().first] = nums[i];

                cout << st.top().first << "----> " << nums[i] << endl;

                if (!visited[i])
                    res.push_back(nums[i]);

                visited[st.top().second] = true;

                st.pop();
            }
            st.push(make_pair(nums[i], i));
        }

        while (!st.empty()) {
            mp[st.top().first] = -1;
            pair<int, int> pr = st.top();

            cout << pr.first << "----> " << -1 << " index : " << pr.second
                 << endl;

            st.pop();
        }

        unordered_map<int, int>::iterator it = mp.begin();

        while (it != mp.end()) {

            cout << it->first << "  " << it->second << endl;

            it++;
        }

        return res;
    }
};

Solution sol;

int main() {

    vector<int> nums{1, 2, 1};
    vector<int> res = sol.nextGreaterElements(nums);

    util.printVector(res);

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();