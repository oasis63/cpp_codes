#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

class Solution {
 public:
  void trim(string& s) {
    int n = s.length();
    int i = 0;
    // remove from start
    while (i < n && s[i] == ' ') {
      i++;
    }

    s.erase(0, i);

    // remove from end

    n = s.length();
    i = n - 1;
    while (i >= 0 && s[i] == ' ') {
      i--;
    }

    s.erase(i + 1);
  }

  int calculate(string s) {
    int res = 0;

    trim(s);

    cout << s.length() << "----" << s << endl;

    string operators = "+-*/";

    stack<int> stk;

    int n = s.length();

    bool newNumber = true;
    char currOperator = '+';

    int currNum = 0;

    for (int i = 0; i <= n; i++) {
      if (i < n && isdigit(s[i])) {
        int num = s[i] - '0';
        currNum = currNum * 10 + num;
      }

      if (i == n || (!isdigit(s[i]) && s[i] != ' ')) {
        if (currOperator == '+') {
          stk.push(currNum);
        }

        if (currOperator == '-') {
          stk.push(-currNum);
        }

        if (currOperator == '*') {
          // stk.push(currNum);

          int prevNumber = stk.top();
          stk.pop();
          int result1 = prevNumber * currNum;

          stk.push(result1);
        }

        if (currOperator == '/') {
          // stk.push(currNum);

          int prevNumber = stk.top();
          stk.pop();
          int result1 = prevNumber / currNum;

          stk.push(result1);
        }

        currOperator = s[i];
        currNum = 0;
      }
    }

    res = 0;

    while (!stk.empty()) {
      res += stk.top();
      stk.pop();
    }

    // int sz = stk.size();
    // cout << "stack size : " << sz << endl;

    // res = stk.top();

    return res;
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  string str;
  cin >> str;

  cout << str.length() << endl;
  cout << str << endl;

  int result = sol.calculate(str);

  cout << "result : " << result << endl;

  return 0;
}