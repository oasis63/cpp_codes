#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stk;

    string operands = "+-*/";

    for (auto& tok : tokens) {
      // cout << tok << endl;

      if (operands.find(tok) != string::npos) {
        // cout << "token : " << endl;
        // let's say the stack always has size more than 2

        int num1 = stk.top();
        stk.pop();
        int num2 = stk.top();
        stk.pop();

        int res = 0;

        if (tok == "+") {
          res = num1 + num2;
        } else if (tok == "-") {
          res = num2 - num1;
        } else if (tok == "*") {
          res = num1 * num2;
        } else {
          res = num2 / num1;
        }

        stk.push(res);

      } else {
        int num = stoi(tok);
        // cout << "number " << stoi(tok) << endl;
        stk.push(num);
      }
    }

    int result = stk.top();

    // bug(result);

    // bug(stk.size());

    // return 0;

    return result;
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

  vector<string> tokens = parseVector<string>(line);

  printVect(tokens);

  cout << "Solution started ...." << endl;
  int ans = sol.evalRPN(tokens);

  cout << "ans : " << ans << endl;

  return 0;
}