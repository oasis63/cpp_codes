#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

string solve(string &str) {
  vector<int> freq(26, 0);

  int n = str.length();

  for (char c : str) {
    freq[c - 'a']++;
  }

  bool middle_taken = false;
  int taken = 0;
  for (int i = 0; i < 26; i++) {
    // odd frequency
    if (freq[i] % 2 == 1) {
      if (n % 2 == 0 || middle_taken) {
        return "NO SOLUTION";
      } else {
        middle_taken = true;
        str[n / 2] = 'a' + i;

        freq[i]--;
      }
    }
    // even frequency
    int half = freq[i] / 2;
    for (int j = 0; j < half; j++) {
      str[taken + j] = str[n - j - taken - 1] = 'a' + i;
    }
    taken += half;
  }

  return str;
}

int main() {
  fast;
  // freopen("input2.txt", "r", stdin);
  // freopen("output2.txt", "w", stdout);

  int tc;
  cin >> tc;
  cin.ignore();

  while (tc--) {
    string str;
    getline(cin, str);

    string str1 = str + str;
    // cout << str1 << endl;

    string res = solve(str1);

    cout << res << endl;
  }

  return 0;
}

/*

input : AAAACACBA

output :  AACABACAA


*/