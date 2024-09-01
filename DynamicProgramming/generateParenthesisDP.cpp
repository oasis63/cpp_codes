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
    bool isBalanced(string str) {
        stack<char> st;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                st.push('(');
            } else {
                if (st.empty()) {
                    return false;
                }
                if (st.top() != '(') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }

    void solve(int n, int open, int close, string current,
               vector<string> &result) {
        // base case

        if (current.length() == 2 * n) {
            if (isBalanced(current)) {
                result.push_back(current);
            }
            return;
        }

        if (open < n) {
            current.push_back('(');
            solve(n, open + 1, close, current, result);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            solve(n, open, close + 1, current, result);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> vect;
        string current = "";
        solve(n, 0, 0, current, vect);
        return vect;
    }
};

int main() {

    fstream fs;
    fs.open("inputs.txt");

    auto start = chrono::high_resolution_clock::now();

    Util util;
    Solution sol;
    int n = 3;
    // fs >> n;

    // cout << sol.isBalanced("())") << endl;

    // vector<string> strs;
    // string temp;

    // while (fs >> temp) {
    //     strs.push_back(temp);
    // }

    // util.printVector(strs);

    // while (fs >> n) {
    //     cout << n << endl;
    // }

    vector<string> res = sol.generateParenthesis(n);

    util.printVector(res);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;

    fs.close();
    return 0;
}
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();