#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class TrieNode {
 public:
  bool is_end;
  TrieNode* children[26];

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      this->children[i] = NULL;
    }
    is_end = false;
  }
};

void insert_trie(TrieNode* root, string word) {
  TrieNode* curr = root;

  for (char& c : word) {
    int key = c - 'a';

    if (!curr->children[key]) {
      curr->children[key] = new TrieNode();
    }

    curr = curr->children[key];
  }
  curr->is_end = true;
}

bool search_trie(TrieNode* root, string word) {
  TrieNode* curr = root;

  for (char& c : word) {
    int key = c - 'a';

    if (!curr->children[key]) {
      return false;
    }
    curr = curr->children[key];
  }
  return true;
}

class Solution {
 public:
  int countPrefixSuffixPairs(vector<string>& words) {
    int n = words.size();
    int pairs = 0;

    for (int i = 0; i < n; i++) {
      TrieNode* suffix = new TrieNode();
      TrieNode* prefix = new TrieNode();

      string curr_str = words[i];
      string rev_curr = curr_str;
      reverse(rev_curr.begin(), rev_curr.end());

      insert_trie(prefix, curr_str);
      insert_trie(suffix, rev_curr);

      for (int j = 0; j < i; j++) {
        // skip the larger length words[j] compare to words[i]
        if (words[j].length() > words[i].length())
          continue;

        string curr_j = words[j];
        string rev_j = curr_j;
        reverse(rev_j.begin(), rev_j.end());

        if (search_trie(prefix, curr_j) && search_trie(suffix, rev_j)) {
          pairs++;
        }
      }
    }

    return pairs;
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

  cout << "Solution started ...." << endl;
  int ans = sol.countPrefixSuffixPairs(words);

  cout << "ans : " << ans << endl;

  return 0;
}