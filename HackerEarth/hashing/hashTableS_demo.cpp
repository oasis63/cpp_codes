#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s, t;
  for (; n > 0; n--) {
    cin >> s >> t;
    int hashTableS[26];
    int hashTableT[26];

    memset(hashTableS, 0, sizeof(int) * 26);
    memset(hashTableT, 0, sizeof(int) * 26);

    for (int i = 0; i < s.length(); i++) {
      hashTableS[s[i] - 'a']++;
    }

    for (int i = 0; i < t.length(); i++) {
      hashTableT[t[i] - 'a']++;
    }

    int ans = 0;

    for (int i = 0; i < 26; i++) {
      hashTableT[i] = hashTableT[i] - hashTableS[i];
      ans += abs(hashTableT[i]);
    }

    cout << ans << endl;
  }
}
