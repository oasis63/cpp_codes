#include <bits/stdc++.h>
using namespace std;

class Util {
  public:
    template <typename T> void printSet(const set<T> &s) {
        for (const auto &element : s) {
            cout << element;
        }
        cout << endl;
    }
    template <typename T> void printVector(const vector<T> &v) {
        for (const auto &element : v) {
            cout << element;
        }
        cout << endl;
    }
};
class Solution {

  private:
    vector<int> uglyNumbers;
    vector<bool> mp;

    bool isUgly(int n) {
        if (n <= 0)
            return false;
        while (n % 2 == 0)
            n /= 2;
        while (n % 3 == 0)
            n /= 3;
        while (n % 5 == 0)
            n /= 5;
        return n == 1;
    }

  public:
    Solution() { mp.assign(1691, false); }

    void findUglyNumbers(int n) {
        int curr = 0;
        int curr_num = 1;
        while (curr != n) {
            if (isUgly(curr_num)) {
                uglyNumbers.push_back(curr_num);
                curr++;
            }
            curr_num++;
        }
    }

    int nthUglyNumber(int n) {

        Util util;
        util.printVector(mp);

        findUglyNumbers(n);
        return uglyNumbers[n - 1];
    }
};

int main() {
    Solution sol;

    int n = 1000;

    cout << sol.nthUglyNumber(n) << endl;
    return 0;
}