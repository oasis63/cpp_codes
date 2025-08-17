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
  return (curr != NULL && curr->is_end);
}

bool recur_search_trie(TrieNode* root, TrieNode* curr, string word, int ind,
                       int n) {
  if (ind >= n) {
    return true;
  }

  int key = word[ind] - 'a';

  if (!curr->children[key]) {
    return false;
  }

  return recur_search_trie(root, curr->children[key], word, ind + 1, n);
}
