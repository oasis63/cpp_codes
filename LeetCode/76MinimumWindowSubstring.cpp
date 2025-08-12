
class Solution {
 public:
  bool sameFreq(int* s, int* t) {
    for (int i = 0; i < 52; i++) {
      if (s[i] < t[i]) {
        return false;
      }
    }
    return true;
  }

  string minWindow(string s, string t) {
    int n1 = s.length();
    int n2 = t.length();

    if (n1 < n2)
      return "";

    int freqS[52] = {0};
    int freqT[52] = {0};

    for (auto& c : t) {
      if (islower(c)) {
        freqT[c - 'a']++;
      } else if (isupper(c)) {
        freqT[26 + c - 'A']++;
      }
    }

    for (int i = 0; i < n2; i++) {
      // freqS[s[i] - diff]++;

      char c = s[i];
      if (islower(c)) {
        freqS[c - 'a']++;
      } else if (isupper(c)) {
        freqS[26 + c - 'A']++;
      }
    }

    string ans = "";

    if (sameFreq(freqS, freqT)) {
      ans = s.substr(0, n2);
      return ans;
    }

    int left = 0, right = n2;
    int startIndex = -1;
    int minLen = INT_MAX;

    while (left < right && left <= n1 && right <= n1) {
      if (sameFreq(freqS, freqT)) {
        if ((right - left) < minLen) {
          // ans = s.substr(left, right - left);
          minLen = right - left;
          startIndex = left;
        }

        char c = s[left];
        if (islower(c)) {
          freqS[c - 'a']--;
        } else if (isupper(c)) {
          freqS[26 + c - 'A']--;
        }

        // freqS[s[left] - diff]--;

        left++;
      } else {
        if (right < n1) {
          char c = s[right];
          if (islower(c)) {
            freqS[c - 'a']++;
          } else if (isupper(c)) {
            freqS[26 + c - 'A']++;
          }

          // freqS[s[right] - diff]++;
        }
        right++;
      }
    }

    return (startIndex == -1) ? "" : s.substr(startIndex, minLen);

    return ans;
  }
};