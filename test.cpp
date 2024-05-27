#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();

        int i = len - 1;
        int sum = 0;
        int carry = 1;

        do {

            sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;

            i--;

        } while (carry == 1 && i >= 0);

        if (carry == 1)
            digits.emplace(digits.begin(), 1);

        return digits;
    }
};

int main() {

    Solution s;

    // vector<int> nums{1, 3, 5, 6};
    vector<int> nums{9};

    vector<int> ans = s.plusOne(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}