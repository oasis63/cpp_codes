#include <bits/stdc++.h>
using namespace std;

int main() {

    int minDel = 0;

    // string input = "()((())";
    string input = "(()))((())";

    stack<char> stk;
    int n = input.length();

    for (int i = 0; i < n; i++) {
        char cr = input[i];

        if (cr == ')') {
            if (!stk.empty() && stk.top() == '(') {
                stk.pop();
            } else {
                minDel++;
            }
        } else if (cr == '(') {
            stk.push('(');
        }
    }

    minDel += stk.size();

    cout << "minimum deletions : " << minDel << endl;

    return 0;
}

/*

Q1: Balancing Parenthesis: Given a string of parenthesis you have to print the
minimum number of deletions that can be made so to balance the parenthesis.

For ex:  Input: “()((())”

Output: 1

*/