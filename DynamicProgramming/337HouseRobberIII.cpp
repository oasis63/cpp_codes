#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// House Robber III

class Data {
 public:
  int first;
  int second;
  int third;
};

class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int key) {
    val = key;
    left = NULL;
    right = NULL;
  }
};

// LRD
void preorder(TreeNode* root) {
  if (root) {
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

// LDR
void inorder(TreeNode* root) {
  if (root) {
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  }
}

class Solution {
 public:
  Data solve(TreeNode* root) {
    // base cases
    if (!root) return {0, 0, 0};

    // leave node
    if (!root->left && !root->right) {
      return {root->val, 0, 0};
    }

    Data sub_left = solve(root->left);
    Data sub_right = solve(root->right);

    int first_element = root->val + max(sub_left.second + sub_right.second,
                                        sub_left.third + sub_right.third);
    int second_element = sub_left.first + sub_right.first;
    // int third_element = sub_left.second + sub_right.second;
    int third_element =
        max({sub_left.first, sub_left.second, sub_left.third}) +
        max({sub_right.first, sub_right.second, sub_right.third});

    return {first_element, second_element, third_element};
  }

  int rob(TreeNode* root) {
    // int res = 0;

    Data result = solve(root);

    return max({result.first, result.second, result.third});

    // cout << "first_element : " << result.first << endl;
    // cout << "second_element : " << result.second << endl;

    // return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  // 7
  TreeNode* root = NULL;
  root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(1);
  root->left->right = new TreeNode(3);

  // 9
  // TreeNode* root = NULL;
  // root = new TreeNode(3);
  // root->left = new TreeNode(4);
  // root->right = new TreeNode(5);
  // root->right->right = new TreeNode(1);
  // root->left->right = new TreeNode(3);
  // root->left->left = new TreeNode(1);

  // 7
  // TreeNode* root = NULL;
  // root = new TreeNode(4);
  // root->left = new TreeNode(1);
  // root->left->left = new TreeNode(2);
  // root->left->left->left = new TreeNode(3);

  // 7
  // TreeNode* root = NULL;
  // root = new TreeNode(2);
  // root->left = new TreeNode(1);
  // root->left->right = new TreeNode(4);
  // root->right = new TreeNode(3);

  int res = sol.rob(root);

  cout << "\nresult : " << res << endl;

  return 0;
}