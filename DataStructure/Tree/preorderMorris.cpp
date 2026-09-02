#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, left child and right child */
class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int x) {
    left = NULL;
    right = NULL;
    data = x;
  }
};

void preorder(Node* root) {
  if (root) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(Node* root) {
  if (root) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

void postorder(Node* root) {
  if (root) {
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }
}

// Morris Algorithm for Interative Preorder Traversal

// DLR
void preorderIterativeUsingStack(Node* root) {
  stack<Node*> stk;

  stk.push(root);

  while (!stk.empty()) {
    Node* curr = stk.top();
    stk.pop();
    cout << curr->data << " ";

    if (curr->right) {
      stk.push(curr->right);
    }
    if (curr->left) {
      stk.push(curr->left);
    }
  }
}

// mod-version 2.0
// instead of pushing the LEFT NODE
/*

1. push the root node in the stack
2. keep printing the left node and simultaneously pushing the right child in the stack.
3. once we reach a null node, pop a right child from the stack and repeat the process
until the stack is empty

*/

// DLR
void preorderIterativeUsingStack2(Node* root) {
  // now the stack keeps only the right children
  stack<Node*> stk;

  Node* curr = root;

  while (!stk.empty() || curr != nullptr) {
    while (curr) {
      cout << curr->data << " ";
      if (curr->right) {
        stk.push(curr->right);
      }
      curr = curr->left;
    }

    if (!stk.empty()) {
      curr = stk.top();
      stk.pop();
    }
  }
}

// Morris Preorder
// without using stack
void preorderMorris(Node* root) {
  Node* curr = root;

  while (curr) {
    if (!curr->left) {
      // no left subtree, visit current , move right
      cout << curr->data << " ";
      curr = curr->right;
    } else {
      // have left subtree
      // Find inorder predecessor: rightmost node in left subtree
      Node* pred = curr->left;
      while (pred->right && pred->right != curr) {
        pred = pred->right;
      }

      if (!pred->right) {
        // First time visiting curr : visit NOW ( this is the preorder trick)
        cout << curr->data << " ";
        pred->right = curr;
        curr = curr->left;
      } else {
        // second time arriving here: thread already exists, means
        // we've finished the left subtree - remove thread, go right
        pred->right = nullptr;
        curr = curr->right;
      }
    }
  }
}

// Driver program to test above functions
int main() {
  /* Constructed binary tree is
          10
        /   \
      8      2
    /  \    /
  3     5  9
*/
  Node* root = new Node(10);
  root->left = new Node(8);
  root->right = new Node(2);
  root->left->left = new Node(3);
  root->left->right = new Node(5);
  root->right->left = new Node(9);

  cout << "Preorder : " << endl;
  preorder(root);

  cout << "\npreorderIterativeUsingStack " << endl;
  preorderIterativeUsingStack(root);

  cout << "\npreorderIterativeUsingStack2 " << endl;
  preorderIterativeUsingStack2(root);

  cout << "\npreorderMorris " << endl;
  preorderMorris(root);

  cout << "\nInorder : " << endl;
  inorder(root);

  cout << "\nPostorder : " << endl;
  postorder(root);

  cout << endl;

  return 0;
}