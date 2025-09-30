#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;

    vector<string> tmp;

    string str = "";

    int curr_len = 0;

    int total_words_len = 0;

    for (string& word : words) {
      int word_len = word.length();

      if (curr_len == 0) {
        if (word_len >= (maxWidth - 1)) {
          curr_len = 0;
          total_words_len = 0;
          ans.push_back(word);
        } else {
          curr_len = word_len;
          tmp.push_back(word);
          total_words_len = word_len;
        }
      } else {
        if ((curr_len + word_len) < maxWidth) {
          curr_len += word_len + 1;
          tmp.push_back(word);
          total_words_len += word_len;
        } else {
          int tmp_len = tmp.size();
          int remaining_space = maxWidth - total_words_len;
          int divisions = tmp_len - 1;

          str = "";

          if (divisions > 0) {
            int spaces = remaining_space / divisions;
            int rem = remaining_space % divisions;

            for (int i = 0; i < tmp_len - 1; i++) {
              str += tmp[i];
              str += string(spaces + (i < rem ? 1 : 0), ' ');
            }
            str += tmp.back();
          } else {
            str = tmp[0] + string(remaining_space, ' ');
          }

          ans.push_back(str);

          tmp.clear();
          curr_len = word_len;
          tmp.push_back(word);
          total_words_len = word_len;
        }
      }
    }

    int tmp_len = tmp.size();

    bug(tmp_len, curr_len, total_words_len);
    str = "";
    for (string& s : tmp) {
      if (str.empty()) {
        str = s;
      } else {
        str += " " + s;
        // str += s;
      }
    }

    bug(str.length());

    while ((int)str.length() < maxWidth) {
      // str.push_back(" ");
      str += " ";
    }

    ans.push_back(str);

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line;
  getline(cin, line);

  vector<string> words = parseVector<string>(line);

  printVect(words);

  int maxWidth;
  cin >> maxWidth;

  bug(maxWidth);

  cout << "Solution started ...." << endl;
  vector<string> ans = sol.fullJustify(words, maxWidth);

  cout << "\nFinal Ans : " << endl;
  for (string& s : ans) {
    cout << "|" << s << "|" << endl;
  }

  return 0;
}

/*


[
   "This    is    an",
   "example  of text",
   "justification.  "
]


*/