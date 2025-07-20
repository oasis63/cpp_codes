#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class TrieNode {
 public:
  unordered_map<string, TrieNode*> children;
  bool is_end;

  TrieNode() {
    this->is_end = false;
  }
};

void insert1(TrieNode* root, vector<string>& strs) {
  TrieNode* pCrawler = root;

  for (string& str : strs) {
    if (pCrawler->children.count(str) == 0) {
      pCrawler->children[str] = new TrieNode();
    }
    pCrawler = pCrawler->children[str];
  }

  pCrawler->is_end = true;
}

void insert(TrieNode* pCrawler, string str, bool is_end_of_string) {
  // TrieNode* pCrawler = root;

  // for (string& str : strs) {
  if (pCrawler->children.count(str) == 0) {
    pCrawler->children[str] = new TrieNode();
  }
  pCrawler = pCrawler->children[str];
  // }

  pCrawler->is_end = is_end_of_string;
}

void dfs(TrieNode* currNode, vector<string>& final_result, string curr_path) {
  if (currNode->is_end) {
    final_result.push_back(curr_path);
    return;
  }
  // iterate over all the map currNode children

  for (auto& [strValue, childNode] : currNode->children) {
    dfs(childNode, final_result, curr_path + strValue);
  }
}

class Solution {
 public:
  //  insert data in Trie
  void process(TrieNode* root, string& str) {
    vector<string> vect;
    int n = str.length();

    TrieNode* pCrawler = root;

    string temp = "";

    for (int i = 0; i < n; i++) {
      if (str[i] == '/') {
        if (temp != "") {
          // vect.push_back(temp);
          if (pCrawler->children.count(temp) == 0) {
            pCrawler->children[temp] = new TrieNode();
          }
          pCrawler = pCrawler->children[temp];
        }
        temp = "";
        temp += str[i];
      } else {
        temp.push_back(str[i]);
      }
    }

    // vect.push_back(temp);

    if (pCrawler->children.count(temp) == 0) {
      pCrawler->children[temp] = new TrieNode();
    }
    pCrawler = pCrawler->children[temp];

    pCrawler->is_end = true;
  }

  vector<string> removeSubfolders(vector<string>& folder) {
    TrieNode* root = new TrieNode();

    for (string& str : folder) {
      process(root, str);
    }

    vector<string> final_result;

    for (auto& [strValue, childNode] : root->children) {
      dfs(childNode, final_result, strValue);
    }

    return final_result;
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

  vector<string> folder = parseVector<string>(line);

  printVect(folder);

  cout << "\nSolution started ....\n"
       << endl;
  vector<string> ans = sol.removeSubfolders(folder);

  cout << "\nAns " << endl;
  printVect(ans);

  return 0;
}