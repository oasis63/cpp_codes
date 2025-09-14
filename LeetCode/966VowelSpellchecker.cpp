#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// 966. Vowel Spellchecker

class Solution {
 public:
  const string vowels = "aeiou";

  void generalizeVowels(string& key) {
    for (char& c : key) {
      if (vowels.find(c) != string::npos) {
        c = 'a';
      }
    }
  }

  bool check(string word1, string word2) {
    transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    transform(word2.begin(), word2.end(), word2.begin(), ::tolower);

    return word1 == word2;
  }

  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    vector<string> result;

    unordered_map<string, vector<string>> mp;
    unordered_set<string> exact;

    for (string& word : wordlist) {
      string key = word;

      exact.insert(word);

      transform(key.begin(), key.end(), key.begin(), ::tolower);

      generalizeVowels(key);

      mp[key].push_back(word);
    }

    for (string& q : queries) {
      if (exact.count(q)) {
        result.push_back(q);
      } else {
        string q_k = q;
        transform(q_k.begin(), q_k.end(), q_k.begin(), ::tolower);

        generalizeVowels(q_k);

        if (mp.count(q_k)) {
          auto& v = mp[q_k];

          string qs = "";

          for (string& rv : v) {
            if (check(q, rv)) {
              if (rv == q) {
                qs = rv;
              } else if (qs == "") {
                qs = rv;
              }
            }
          }
          if (qs == "") {
            qs = v[0];
          }
          result.push_back(qs);
        } else {
          result.push_back("");
        }
      }
    }

    return result;
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

  vector<string> wordlist = parseVector<string>(line);

  getline(cin, line);

  vector<string> queries = parseVector<string>(line);

  printVect(wordlist);
  printVect(queries);

  vector<string> result = sol.spellchecker(wordlist, queries);

  printVect(result);

  return 0;
}