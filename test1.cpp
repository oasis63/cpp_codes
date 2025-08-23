#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class TrieNode {
 public:
  unordered_map<char, TrieNode*> children;
  bool is_end;

  TrieNode() {
    this->is_end = false;
  }
};

void insert_trie(TrieNode* root, string word) {
  TrieNode* curr = root;
  int len = word.length();

  for (int i = 0; i < len; i++) {
    if (!curr->children.count(word[i])) {
      curr->children[word[i]] = new TrieNode();
    }
    curr = curr->children[word[i]];
  }
  curr->is_end = true;
}

bool sol_search(TrieNode* curr, int ind, string word) {
  if (ind == (int)word.length()) {
    return true;
  }

  int res = false;

  for (auto& [curr_char, next_node] : curr->children) {
    int new_ind = ind;
    if (word[ind] == curr_char) {
      new_ind += 1;
    }

    res = sol_search(next_node, new_ind, word);
    if (res)
      return true;
  }

  return res;
}

class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& words) {
    int matches = 0;

    TrieNode* root = new TrieNode();
    insert_trie(root, s);

    set<string> st;

    for (string& word : words) {
      TrieNode* curr = root;

      if (st.find(word) != st.end()) {
        matches++;
        continue;
      }

      if (sol_search(curr, 0, word)) {
        matches++;
        st.insert(word);
      }
    }

    return matches;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string str;
  getline(cin, str);

  string line;
  getline(cin, line);

  vector<string> words = parseVector<string>(line);

  bug(str);
  printVector(words);

  cout << "Solution started ...." << endl;
  int ans = sol.numMatchingSubseq(str, words);

  cout << "ans : " << ans << endl;

  return 0;
}