#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

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

void insert_trie(TrieNode* root, string& word) {
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

bool search_trie(TrieNode* root, string& word) {
  TrieNode* curr = root;
  for (char& c : word) {
    int key = c - 'a';
    if (!curr->children[key]) {
      return false;
    }
    curr = curr->children[key];
  }
  return curr->is_end;
}

// do a dfs to get all the string with ending words

void dfs(TrieNode* currNode, string currStr, vector<string>& res) {
  if (currNode->is_end) {
    res.push_back(currStr);

    if (res.size() >= 3)
      return;
  }

  for (int i = 0; i < 26; i++) {
    if (currNode->children[i]) {
      dfs(currNode->children[i], currStr + (char)('a' + i), res);
    }
  }

  return;
}

void getSuggestions(TrieNode* root, string str, vector<string>& res) {
  TrieNode* currNode = root;

  for (char& c : str) {
    int key = c - 'a';
    if (!currNode->children[key])
      return;
    currNode = currNode->children[key];
  }

  dfs(currNode, str, res);
}

class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    TrieNode* root = new TrieNode();

    for (string& product : products) {
      insert_trie(root, product);
    }

    // for (string& product : products) {
    //   bool res = search_trie(root, product);
    //   bug(product, res);
    // }

    vector<vector<string>> suggestions;

    int len = searchWord.length();

    string currStr;

    for (int i = 0; i < len; i++) {
      vector<string> res;
      currStr.push_back(searchWord[i]);

      bug(currStr);

      getSuggestions(root, currStr, res);

      suggestions.push_back(res);
    }

    return suggestions;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line, searchWord;
  getline(cin, line);

  vector<string> products = parseVector<string>(line);

  getline(cin, searchWord);

  cout << "Solution started ...." << endl;
  vector<vector<string>> ans = sol.suggestedProducts(products, searchWord);

  cout << "Suggested Products \n";

  bug(ans.size());

  print2DVector(ans);

  return 0;
}