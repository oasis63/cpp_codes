/*
total = 1 << k : 1 shifted to the left k times is equal to 2^k.
allOnes = total - 1: A power of 2 substracted by 1 gives the previous value
which is a number filled with 1s of length k. Try this out for some values. if
(i >= k-1 && codes.add(hashCode) && codes.size() == total): Return true only if
our substring is of length k, and; if the current hashCode doesn't exist in our
set yet, and; if our set size has all 2^k elements.

*/

// 1461. Check If a String Contains All Binary Codes of Size K

class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    unordered_set<int> bitStrings;
    int total = 1 << k;
    int allOnes = total - 1;

    int n = s.length();

    int window;
    for (int i = 0; i < k && i < n; i++) {
      window = ((window << 1) & allOnes) | (s[i] - '0');
    }

    bitStrings.insert(window);

    if ((int)bitStrings.size() == total)
      return true;

    for (int i = k; i < n; i++) {
      window = ((window << 1) & allOnes) | (s[i] - '0');

      bitStrings.insert(window);
      if ((int)bitStrings.size() == total)
        return true;
    }

    return false;
  }
};