#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// 720. Longest Word in Dictionary

class TrieNode {
 public:
  TrieNode* children[26];
  bool is_end;

  TrieNode() {
    this->is_end = false;
    for (int i = 0; i < 26; i++) {
      this->children[i] = NULL;
    }
  }
};

void insert_trie(TrieNode* root, string word) {
  TrieNode* curr = root;

  int len = word.length();

  int ends = 0;

  for (int i = 0; i < len; i++) {
    int key = word[i] - 'a';
    if (!curr->children[key]) {
      curr->children[key] = new TrieNode();
    }
    curr = curr->children[key];

    if (curr->is_end)
      ends++;
  }
  curr->is_end = true;
}

bool search_trie(TrieNode* root, string word) {
  TrieNode* curr = root;
  int len = word.length();
  for (int i = 0; i < len; i++) {
    int key = word[i] - 'a';
    if (!curr->children[key]) {
      curr->children[key] = new TrieNode();
    }
    curr = curr->children[key];
  }
  return curr->is_end;
}

void getLongWord(TrieNode* curr, string& ans, string temp) {
  if (curr->is_end && ans.length() <= temp.length()) {
    if (ans.length() == temp.length()) {
      // smaller lexigcographical
      ans = min(ans, temp);
    } else {
      ans = temp;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (curr->children[i] && curr->children[i]->is_end) {
      getLongWord(curr->children[i], ans, temp + (char)('a' + i));
    }
  }

  return;
}

class Solution {
 public:
  string longestWord(vector<string>& words) {
    TrieNode* root = new TrieNode();

    for (string& word : words) {
      insert_trie(root, word);
    }

    string ans = "";
    string temp = "";

    getLongWord(root, ans, temp);

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

  cout << "Solution started ...." << endl;
  string ans = sol.longestWord(words);

  cout << "Final Answer : " << ans << endl;

  return 0;
}