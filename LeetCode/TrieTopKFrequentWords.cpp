#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

struct my_comp {
  bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second > b.second;
  }
};

class TrieNode {
 public:
  TrieNode* children[26];
  bool is_end;
  int freq;

  TrieNode() {
    this->is_end = false;
    this->freq = 0;
    for (int i = 0; i < 26; i++) {
      this->children[i] = NULL;
    }
  }
};

// min heap
priority_queue<pair<string, int>, vector<pair<string, int>>, my_comp> min_heap;

void insert_trie(TrieNode* root, string word) {
  TrieNode* curr = root;
  int len = word.length();
  for (int i = 0; i < len; i++) {
    int key = word[i] - 'a';
    if (!curr->children[key]) {
      curr->children[key] = new TrieNode();
    }
    curr = curr->children[key];
  }
  curr->is_end = true;
  curr->freq++;
}

void search_trie(TrieNode* curr, string temp, int k) {
  if (curr->is_end) {
    // vect.push_back({temp, curr->freq});
    min_heap.push({temp, curr->freq});

    if ((int)min_heap.size() > k) {
      min_heap.pop();
    }
  }

  for (int i = 0; i < 26; i++) {
    if (!curr->children[i])
      continue;
    search_trie(curr->children[i], temp + (char)('a' + i), k);
  }

  return;
}

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    TrieNode* root = new TrieNode();

    for (string& word : words) {
      insert_trie(root, word);
    }

    // vector<pair<string, int>> vect;
    // search_trie(root, vect, "", k);
    search_trie(root, "", k);

    vector<string> ans1;

    while (!min_heap.empty()) {
      cout << min_heap.top().first << " " << min_heap.top().second << endl;
      ans1.push_back(min_heap.top().first);
      min_heap.pop();
    }

    reverse(ans1.begin(), ans1.end());
    printVector(ans1);

    return ans1;

    // sort(vect.begin(), vect.end(), [](const auto& a, const auto& b) {
    //   if (a.second == b.second) {
    //     return a.first < b.first;
    //   }
    //   return a.second > b.second;
    // });

    // vector<string> ans;
    // for (auto& v : vect) {
    //   ans.push_back(v.first);
    //   k--;
    //   if (k == 0)
    //     break;
    // }

    // return ans;
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

  int k;
  cin >> k;

  printVect(words);

  cout << "Solution started ...." << endl;
  vector<string> ans = sol.topKFrequent(words, k);

  printVect(ans);

  return 0;
}