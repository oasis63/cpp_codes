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
};

class Solution {
  public:
    vector<string> split(const string &str, char delimiter) {
        vector<string> tokens;
        stringstream ss(str);
        string token;

        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }

        return tokens;
    }

    string simplifyPath(string path) {
        vector<string> result = split(path, '/');
        int n = result.size();
        stack<string> stk;

        for (string st : result) {
            if (st == "..") {
                if (!stk.empty())
                    stk.pop();
            } else {
                if (st != "" && st != ".")
                    stk.push(st);
            }
        }
        string ans = "";
        while (!stk.empty()) {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        return ans == "" ? "/" : ans;
    }
};

int main() {
    Util util;
    Solution sol;
    // string path = "/home/user/Documents/../Pictures";
    // string path = "/home//foo/";
    // string path = "/../";
    // string path = "/.../a/../b/c/../d/./";
    string path = "/home/";
    cout << sol.simplifyPath(path) << endl;

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();