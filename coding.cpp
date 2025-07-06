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
    int divide(int dividend, int divisor) {
        int maxInt = INT_MAX;
        int minInt = INT_MIN;

        // cout << "maxInt : " << maxInt << endl;
        // cout << "minINt : " << minInt << endl;

        bool isNegative = dividend < 0 && divisor < 0   ? false
                          : dividend < 0 || divisor < 0 ? true
                                                        : false;
        cout << "isNegative : " << isNegative << endl;

        int res = 0;

        cout << (dividend < 0) << endl;

        if (dividend <= -2147483648)
            dividend = 2147483647;
        else if (dividend >= 2147483647)
            dividend = 2147483647;

        if (divisor <= -2147483648)
            divisor = 2147483647;
        else if (divisor >= 2147483647)
            divisor = 2147483647;

        dividend = dividend < 0 ? dividend * -1 : dividend;
        divisor = divisor < 0 ? divisor * -1 : divisor;

        // if (dividend < minInt) {
        //     dividend = minInt;
        // } else if (dividend > maxInt) {
        //     dividend = maxInt;
        // }

        cout << "dividend  : " << dividend << endl;
        cout << "divisor : " << divisor << endl;

        if (divisor == 1)
            return isNegative ? dividend * -1 : dividend;

        while (dividend >= divisor) {
            dividend -= divisor;
            res++;
        }

        return isNegative ? res * -1 : res;
    }
};

int main() {

    fstream fs;
    fs.open("inputs.txt");
    ofstream outputFile("output.txt");

    auto start = chrono::high_resolution_clock::now();

    Util util;
    Solution sol;

    int dividend = 10, divisor = 3;
    fs >> dividend;
    fs >> divisor;

    // vector<string> strs;
    // string temp;
    // while (fs >> temp) {
    //     strs.push_back(temp);
    // }
    // outputFile << sol.divide(dividend, divisor) << endl;

    cout << sol.divide(dividend, divisor) << endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\nTime taken: " << duration.count() << " ms" << endl;

    fs.close();
    outputFile.close();
    return 0;
}
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();