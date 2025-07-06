#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
        string str = "";

        int len1 = a.length();
        int len2 = b.length();
        int i = len1 - 1;
        int j = len2 - 1;

        bool carry = false;

        while (i >= 0 && j >= 0) {
            if (a[i] == '1' && b[j] == '1') {
                if (carry) {
                    str = "1" + str;
                } else {
                    str = "0" + str;
                }
                carry = true;
            } else if (a[i] == '0' && b[j] == '0') {
                if (carry) {
                    str = "1" + str;
                    carry = false;
                } else {
                    str = "0" + str;
                }
            } else { // one of it has "1"
                if (carry) {
                    str = "0" + str;
                    carry = true;
                } else {
                    str = "1" + str;
                }
            }
            i--;
            j--;
        }

        while (i >= 0) {
            if (a[i] == '1') {
                if (carry) {
                    str = "0" + str;
                    carry = true;
                } else {
                    str = "1" + str;
                }
            } else {
                if (carry) {
                    str = "1" + str;
                    carry = false;
                } else {
                    str = "0" + str;
                }
            }
            i--;
        }

        while (j >= 0) {
            if (b[j] == '1') {
                if (carry) {
                    str = "0" + str;
                    carry = true;
                } else {
                    str = "1" + str;
                }
            } else {
                if (carry) {
                    str = "1" + str;
                    carry = false;
                } else {
                    str = "0" + str;
                }
            }
            j--;
        }

        cout << "carry : " << carry << endl;

        if (carry)
            str = "1" + str;

        return str;
    }
};

int main() {

    Solution obj;
    string a = "1010";
    string b = "1011";
    //         10101

    cout << obj.addBinary(a, b) << endl;

    return 0;
}