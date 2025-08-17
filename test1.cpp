#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

const int MX_SIZE = 26;

class TrieNode {
 public:
  bool is_end;
  TrieNode* children[MX_SIZE];

  TrieNode() {
    this->is_end = false;
    for (int i = 0; i < MX_SIZE; i++) {
      this->children[i] = NULL;
    }
  }
};

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
}

bool search_trie(TrieNode* root, string word) {
  TrieNode* curr = root;

  int len = word.length();
  for (int i = 0; i < len; i++) {
    int key = word[i] - 'a';

    if (!curr->children[key]) {
      return false;
    }

    curr = curr->children[key];
  }

  return (curr && curr->is_end);
  // return true;
}

string mod_search_trie(TrieNode* root, string word) {
  TrieNode* curr = root;

  string found_str = "";

  int len = word.length();
  for (int i = 0; i < len; i++) {
    int key = word[i] - 'a';

    // to get the smallest

    if (curr && curr->is_end) {
      return found_str;
    }

    if (!curr->children[key]) {
      // return false;
      break;
    }
    found_str.push_back(word[i]);
    curr = curr->children[key];
  }

  if (curr && curr->is_end) {
    return found_str;
  }

  return "";
  // return found_str;
  // return (curr && curr->is_end);
  // return true;
}

class Solution {
 public:
  vector<string> split(string str, char delim) {
    vector<string> strs;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delim)) {
      strs.push_back(token);
    }

    return strs;
  }

  string replaceWords(vector<string>& dictionary, string sentence) {
    vector<string> strs = split(sentence, ' ');

    bug(sentence);
    printVector(dictionary);
    printVector(strs);

    // build the trie
    TrieNode* root = new TrieNode();

    for (string& st : dictionary) {
      insert_trie(root, st);
    }

    // for (string& st : dictionary) {
    //   string rs = mod_search_trie(root, st);
    //   bug(rs, st);
    // }

    // unordered_map<string, string> mp;
    string final_str = "";

    int strs_size = strs.size();
    for (int i = 0; i < strs_size; i++) {
      string st = strs[i];
      // iterate over 26 letters
      // take the rs which is not empty and is smallest

      string rs = mod_search_trie(root, st);
      // bug(st, rs);
      if (rs.empty()) {
        // string is not found
        rs = st;
      } else {
        // mp[st] = rs;
      }

      final_str += rs;
      if (i < strs_size - 1) {
        final_str += " ";
      }
    }

    // for (string& st : strs) {
    // }

    return final_str;
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

  vector<string> dict = parseVector<string>(line);

  getline(cin, line);

  string sentence = line;

  cout << "Solution started ...." << endl;
  string ans = sol.replaceWords(dict, sentence);

  cout << "ans : " << ans << endl;

  return 0;
}