#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

int main() {
  string str;
  cin >> str;

  vector<int> freq(26, 0);

  int n = str.length();

  for (char c : str) {
    freq[c - 'A']++;
  }

  bool middle_taken = false;
  int taken = 0;
  for (int i = 0; i < 26; i++) {
    // odd frequency
    if (freq[i] % 2 == 1) {
      if (n % 2 == 0 || middle_taken) {
        cout << "NO SOLUTION" << endl;
        return 0;
      } else {
        middle_taken = true;
        str[n / 2] = 'A' + i;

        freq[i]--;
      }
    }
    // even frequency
    int half = freq[i] / 2;
    for (int j = 0; j < half; j++) {
      str[taken + j] = str[n - j - taken - 1] = 'A' + i;
    }
    taken += half;
  }

  cout << str << endl;
  return 0;
}

/*

input : AAAACACBA

output :  AACABACAA


*/