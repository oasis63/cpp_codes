// Leetcode 211. Design Add and Search Words Data Structure

const int MX_SIZE = 26;

class TrieNode {
 public:
  bool is_end;
  TrieNode* children[MX_SIZE];

  TrieNode() {
    for (int i = 0; i < MX_SIZE; i++) {
      this->children[i] = NULL;
    }
    this->is_end = false;
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
    return curr->is_end;
  }

  if (word[ind] == '.') {
    bool temp_res = false;
    for (int i = 0; i < 26; i++) {
      if (curr->children[i]) {
        temp_res = recur_search_trie(root, curr->children[i], word,
                                     ind + 1, n);
        if (temp_res)
          return true;
      }
    }
    return false;
  }

  int key = word[ind] - 'a';

  if (!curr->children[key]) {
    return false;
  }

  return recur_search_trie(root, curr->children[key], word, ind + 1, n);
}

class WordDictionary {
 public:
  TrieNode* root;
  WordDictionary() {
    root = new TrieNode();
  }

  void addWord(string word) {
    insert_trie(root, word);
  }

  bool search(string word) {
    return recur_search_trie(root, root, word, 0, word.length());
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */