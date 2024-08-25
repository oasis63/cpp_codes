#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int divisorSubstrings(int num, int k) {
        string ns = to_string(num);
        int len = ns.length();
        int ans = 0;
        cout << " ns : " << ns << endl;
        for (int i = 0; i < len - k + 1; i++) {
            string sub = ns.substr(i, k);
            int temp = stoi(sub);
            cout << "sub " << sub << " temp : " << temp << endl;
            if (sub[0] != 0 && temp != 0 && num % temp == 0) {
                cout << " rem : " << num % temp << endl;
                ans++;
            }
        }
        return ans;
    }
};

int main() {

    // set<int> st;
    // int c[3] = {};
    // for (int i = 0; i < 10; i++) {
    //     st.insert(i);
    //     c[i]++;
    // }

    // for (auto n : st) {
    //     cout << "n : " << n << endl;
    // }

    // for (auto n : c) {
    //     cout << "n : " << n << endl;
    // }

    int n = 10;
    cout << n << endl;

    string str = to_string(n) + "";

    cout << str << endl;

    return 0;
}