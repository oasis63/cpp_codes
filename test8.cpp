#include <bits/stdc++.h>
using namespace std;

// longest common substring

int longestCommonSubstring(string str1, string str2, int n, int m) {

    int result = 0;

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    ACDGHR
    return result;
}

int main() {

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;
        string str1, str2;
        cin >> str1;
        cin >> str2;
        cout << longestCommonSubstring(str1, str2, n, m) << endl;
    }
    return 0;
}

/*


2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC




*/
