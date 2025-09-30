#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int calculate(string s) {
    int res = 0;
    int n = s.length();
    stack<string> stk;

    for (int i = 0; i < n; i++) {
      if (s[i] == ' ') {
        cout << "found space \n";
        continue;
      }

      string curr;
      curr.push_back(s[i]);
      bug(curr);
      if (stk.empty()) {
        stk.push(curr);
      } else {
        if (curr == "+" || curr == "-") {  // operator
          stk.push(curr);
        } else if (curr == "(") {  // opening bracket
          stk.push(curr);
        } else if (curr == ")") {  // closing bracket
          // todo: complete the code
          stk.push(curr);
        } else {  // digits
          int digit = stoi(curr);
          // stk.push(curr);
          string tp = stk.top();

          if (tp == "+" || tp == "-") {
            stk.pop();
            string v1 = stk.top();
            stk.pop();

            int value1 = stoi(v1);

            if (tp == "+") {
              value1 += digit;
            } else {
              value1 -= digit;
            }

            stk.push(to_string(value1));
          }
        }
      }
    }

    while (!stk.empty()) {
      cout << stk.top() << " ";
      stk.pop();
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line;
  getline(cin, line);

  bug(line);

  cout << "Solution started ...." << endl;
  int ans = sol.calculate(line);

  cout << "ans : " << ans << endl;

  return 0;
}