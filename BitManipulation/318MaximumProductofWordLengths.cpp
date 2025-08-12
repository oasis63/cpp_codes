#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

// 318. Maximum Product of Word Lengths

class Solution {
 public:
  int bit_len(string word) {
    int mask = 0;

    for (char& w : word) {
      int i = w - 'a';
      // setting the ith bit in mask
      mask = mask | (1 << i);
    }

    return mask;
  }

  int maxProduct(vector<string>& words) {
    int mx_prod = 0;
    int n = words.size();

    vector<int> bitLens;
    for (string& word : words) {
      int ret = bit_len(word);
      // bug(word, ret);
      bitLens.push_back(ret);
    }

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        // both the strings have no common characters
        if ((bitLens[i] & bitLens[j]) == 0) {
          mx_prod = max(mx_prod, (int)words[i].length() * (int)words[j].length());
        }
      }
    }

    return mx_prod;
  }
};

int main() {
  set_io_files("input.txt", "output.txt");

  string line;
  getline(cin, line);

  vector<string> words = parseVector<string>(line);

  printVector<string>(words);

  Solution sol;
  int mx_prod = sol.maxProduct(words);

  bug(mx_prod);

  return 0;
}