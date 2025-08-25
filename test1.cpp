#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class TrieNode {
 public:
  bool is_end;
  unordered_map<char, TrieNode*> children;
  TrieNode() {
    this->is_end = false;
  }
};

void insert_trie(TrieNode* root, string word) {
  TrieNode* curr = root;
  for (char& c : word) {
    if (!curr->children.count(c)) {
      curr->children[c] = new TrieNode();
    }
    curr = curr->children[c];
  }
  curr->is_end = true;
}

int count_min_extras(TrieNode* curr, string str, int ind, int n, int& extras) {
  // base case
  if (ind >= n)
    return INT_MAX;

  // reached to the last character and it matches to the curr->children
  // so no extras will be there

  // found
  if (curr->children.count(str[ind])) {
    curr = curr->children[str[ind]];

    int res1 = count_min_extras(curr, str, ind + 1, n, extras);
  }

  // not found

  return 0;
}

class Solution {
 public:
  int minExtraChar(string s, vector<string>& dictionary) {
    int extras = 0;

    TrieNode* root = new TrieNode();
    for (string& word : dictionary) {
      insert_trie(root, word);
    }

    int len = s.length();

    // count_min_extras(root, s, 0, len, extras);

    TrieNode* curr = root;

    int hit = 0;

    // for (char& c : s) {
    for (int i = 0; i < len; i++) {
      char c = s[i];
      if (curr->children.count(c)) {
        curr = curr->children[c];
        hit++;

        if (curr->is_end) {
          hit = 0;
        }

      } else {
        curr = root;
        // now checking in the root
        if (curr->children.count(c)) {
          curr = curr->children[c];

          if (hit != 0) {
            extras += hit;
          }

          // hit++;  // or hit = 1;
          hit = 1;
        } else {
          // extras += hit;
          extras++;
        }
      }
    }

    cout << "hit : " << hit << endl;

    return extras + hit;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string s, line;
  getline(cin, s);

  getline(cin, line);

  vector<string> dictionary = parseVector<string>(line);

  printVect(dictionary);

  cout << "Solution started ...." << endl;
  int extras = sol.minExtraChar(s, dictionary);

  cout << "extras : " << extras << endl;

  return 0;
}