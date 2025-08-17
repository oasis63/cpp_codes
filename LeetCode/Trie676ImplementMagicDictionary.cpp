class TrieNode {
 public:
  bool is_end;
  TrieNode* children[26];

  TrieNode() {
    this->is_end = false;
    for (int i = 0; i < 26; i++) {
      this->children[i] = NULL;
    }
  }
};

void insert_trie(TrieNode* root, string word) {
  TrieNode* curr = root;
  for (char c : word) {
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
  for (char c : word) {
    int key = c - 'a';
    if (!curr->children[key]) {
      return false;
    }
    curr = curr->children[key];
  }

  return (curr && curr->is_end);
  // return true;
}

bool recur_search_trie(TrieNode* root, TrieNode* curr, string word, int ind,
                       int n, int replace) {
  if (ind >= n)
    return (curr->is_end && replace == 1);

  // only one replace is allowed
  if (replace > 1)
    return false;

  int key = word[ind] - 'a';

  if (!curr->children[key]) {
    bool temp_res = false;
    // start replacing the current character key with
    // the children of the curr
    for (int i = 0; i < 26; i++) {
      if (curr->children[i]) {
        temp_res = recur_search_trie(root, curr->children[i], word,
                                     ind + 1, n, replace + 1);

        if (temp_res)
          return true;
      }
    }

    return false;
  }

  // even though we have a character ,let's try skip the current

  for (int i = 0; i < 26; i++) {
    if (key != i && curr->children[i]) {
      bool res1 = recur_search_trie(root, curr->children[i], word,
                                    ind + 1, n, replace + 1);

      if (res1)
        return true;
    }
  }

  int res =
      recur_search_trie(root, curr->children[key], word, ind + 1, n, replace);

  return res;
}

class MagicDictionary {
 public:
  TrieNode* root;
  MagicDictionary() {
    root = new TrieNode();
  }

  void buildDict(vector<string> dictionary) {
    for (string& word : dictionary) {
      insert_trie(root, word);
    }
  }

  bool search(string searchWord) {
    int replace = 0;
    int len = searchWord.length();

    bool sr = recur_search_trie(root, root, searchWord, 0, len, replace);

    return sr;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */