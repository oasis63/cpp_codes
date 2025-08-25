#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class TrieNode {
 public:
  unordered_map<char, TrieNode*> children;
  bool is_end;
  vector<string> suggestions;

  TrieNode() {
    this->is_end = false;
  }
};

void insert_trie(TrieNode* root, string& word) {
  TrieNode* curr = root;
  for (char& c : word) {
    if (!curr->children.count(c)) {
      curr->children[c] = new TrieNode();
    }
    curr = curr->children[c];

    // inserting the suggestions for each character string
    curr->suggestions.push_back(word);
    sort(curr->suggestions.begin(), curr->suggestions.end());

    if (curr->suggestions.size() > 3) {
      curr->suggestions.pop_back();
    }
  }
  curr->is_end = true;
}

class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products,
                                           string searchWord) {
    TrieNode* root = new TrieNode();

    sort(products.begin(), products.end());

    for (string& product : products) {
      insert_trie(root, product);
    }

    vector<vector<string>> suggestions;

    string currStr;

    TrieNode* currNode = root;

    for (char& c : searchWord) {
      if (currNode && currNode->children.count(c)) {
        currNode = currNode->children[c];
        suggestions.push_back(currNode->suggestions);
      } else {
        currNode = NULL;
        suggestions.push_back({});
      }
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