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
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();

        if (len1 == 1) {
            if (num1[0] == '1')
                return num2;
            if (num1[0] == '0')
                return "0";
        } else if (len2 == 1) {
            if (num2[0] == '1')
                return num1;
            if (num2[0] == '0')
                return "0";
        }

        int carry = 0;
        string zeros = "";

        vector<string> products;

        for (int i = len1 - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            string str = "";
            carry = 0;

            for (int j = len2 - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                int mult = a * b + carry;
                carry = mult / 10;
                mult = mult % 10;

                cout << "a : " << a << " b : " << b << " mult : " << mult
                     << "  carry " << carry << endl;

                str = to_string(mult) + str;
            }
            if (carry) {
                str = to_string(carry) + str;
            }
            str = str + zeros;
            cout << "str : " << str << endl;
            products.push_back(str);
            zeros = zeros + "0";
        }

        string finalProduct = "";
        int maxLen = products[products.size() - 1].length();
        carry = 0;

        int l = 0;
        while (l < maxLen) {
            int sum = carry;
            for (int i = products.size() - 1; i >= 0; i--) {
                int strLen = products[i].length();
                cout << products[i][strLen - 1 - l] << " ";
                if (l < strLen) {
                    int b = products[i][strLen - 1 - l] - '0';
                    sum = sum + b;
                }
            }
            carry = sum / 10;
            sum = sum % 10;
            cout << "\t sum : " << sum << endl;
            finalProduct = to_string(sum) + finalProduct;

            l++;
        }

        if (carry) {
            finalProduct = to_string(1) + finalProduct;
        }

        return finalProduct;
    }
};

int main() {
    Util util;
    Solution sol;
    string num1 = "123456789", num2 = "987654321";
    string res = sol.multiply(num1, num2);
    cout << "ans : " << res << endl;
    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
