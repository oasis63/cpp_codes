#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class TrieNode {
 public:
  bool is_ending;
  unordered_map<char, TrieNode*> children;

  TrieNode() {
    this->is_ending = false;
  }
};

// insert in Trie

void insert(TrieNode* root, string str) {
  TrieNode* pCrawler = root;
  int n = str.length();

  for (char& c : str) {
    if (pCrawler->children.count(c) == 0) {
      pCrawler->children[c] = new TrieNode();
    }

    pCrawler = pCrawler->children[c];
  }

  pCrawler->is_ending = true;
}

bool search(TrieNode* root, string key) {
  TrieNode* pCrawler = root;
  int n = key.length();
  for (char& c : key) {
    if (!pCrawler->children.count(c)) {
      return false;
    }
    pCrawler = pCrawler->children[c];
  }

  return (pCrawler != NULL && pCrawler->is_ending);
}

// print bfs

void bfs(TrieNode* root) {
  queue<TrieNode*> q;
  q.push(root);

  while (!q.empty()) {
    TrieNode* tempNode = q.front();
    q.pop();

    for (auto& [u, v] : tempNode->children) {
      cout << u << " ";
      q.push(v);
    }
  }
  cout << endl;
}

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    // build the trie

    TrieNode* root = new TrieNode();
    for (string& str : strs) {
      insert(root, str);
    }

    string lcp = "";

    TrieNode* pCrawler = root;

    while (pCrawler->children.size() == 1 && !pCrawler->is_ending) {
      for (auto& [u, v] : pCrawler->children) {
        lcp.push_back(u);
        pCrawler = v;
      }
    }

    return lcp;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  string line;
  getline(cin, line);

  bug(line);
  vector<string> strs = parseVector<string>(line);

  printVect(strs);

  cout << "Solution started ...." << endl;

  string ans = sol.longestCommonPrefix(strs);

  cout << "ans : " << ans << endl;

  return 0;
}