#include <bits/stdc++.h>
using namespace std;

class Solution {
    void removeAlphanumeric(string &str) {
        // Remove alphanumeric characters using remove_if and erase
        str.erase(remove_if(str.begin(), str.end(),
                            [](char c) { return !isalnum(c); }),
                  str.end());

        // Convert uppercase to lowercase
        transform(str.begin(), str.end(), str.begin(),
                  [](unsigned char c) { return tolower(c); });
    }

  public:
    bool isPalindrome(string s) {

        removeAlphanumeric(s);

        cout << "s : " << s << endl;

        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main() {

    Solution obj;

    string str = "A man, a plan, a canals: Panama";
    cout << obj.isPalindrome(str) << endl;

    return 0;
}