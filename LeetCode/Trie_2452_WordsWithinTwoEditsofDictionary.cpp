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
  for (char c : word) {
    if (!curr->children.count(c)) {
      curr->children[c] = new TrieNode();
    }
    curr = curr->children[c];
  }

  curr->is_end = true;
}

bool recur_search_trie(TrieNode* curr, string word, int ind, int n,
                       int replace) {
  if (ind >= n)
    return (curr->is_end && replace <= 2);

  // only two replace is allowed
  if (replace > 2)
    return false;

  // curreent character not found
  if (!curr->children.count(word[ind])) {
    bool temp_res = false;
    for (auto& [u, v] : curr->children) {
      temp_res = recur_search_trie(v, word, ind + 1, n, replace + 1);
      if (temp_res)
        return true;
    }
    return false;
  }

  // try checking in all the children node characters of the current node
  for (auto& [u, v] : curr->children) {
    if (word[ind] != u) {
      bool res1 = recur_search_trie(v, word, ind + 1, n, replace + 1);
      if (res1)
        return true;
    }
  }

  int res =
      recur_search_trie(curr->children[word[ind]], word, ind + 1, n, replace);

  return res;
}

class Solution {
 public:
  bool compareTwoStrings(string str1, string str2) {
    int diff = 0;
    int n = str1.length();
    for (int i = 0; i < n; i++) {
      if (str1[i] != str2[i])
        diff++;
      if (diff > 2)
        return false;
    }
    return true;
  }

  vector<string> twoEditWords(vector<string>& queries,
                              vector<string>& dictionary) {
    vector<string> result;

    TrieNode* root = new TrieNode();

    for (string& word : dictionary) {
      insert_trie(root, word);
    }

    for (string& q : queries) {
      TrieNode* curr = root;

      bool isPossible = recur_search_trie(curr, q, 0, (int)q.length(), 0);

      if (isPossible) {
        result.push_back(q);
      }

      // for (string& d : dictionary) {
      //     if (compareTwoStrings(q, d)) {
      //         result.push_back(q);
      //         break;
      //     }
      // }
    }

    return result;
  }
};