#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

// 820. Short Encoding of Words

class Solution {
 public:
  int minimumLengthEncoding(vector<string> &words) {
    // remove the duplicates
    set<string> st;

    for (string &word : words) {
      st.insert(word);
    }

    for (string &word : words) {
      for (int i = 1; i < (int)word.length(); i++) {
        string suffix = word.substr(i);
        // removing all the possible suffixes from the set
        st.erase(suffix);
      }
    }

    int ans = 0;
    string temp_str = "";

    for (auto &word : st) {
      temp_str += word + "#";
      ans += word.length() + 1;
    }

    cout << temp_str << endl;

    return ans;
  }
};

int main() {
  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line;
  getline(cin, line);

  vector<string> words = parseVector<string>(line);

  int res = sol.minimumLengthEncoding(words);

  bug(res);

  return 0;
}