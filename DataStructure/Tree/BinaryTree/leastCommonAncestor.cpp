#include <bits/stdc++.h>
using namespace std;

// INCOMPLETE LEAST COMMON ANCESTOR (LCA)

class Node {
  public:
    int value;
    Node *left;
    Node *right;

    Node(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

Node *newNode(int v) {
    Node *node = new Node(v);
    return node;
}

void preorder(Node *root) {
    if (root) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int find(Node *root, int elem) {
    if (root == NULL)
        return 0;
    else if (root->value == elem)
        return 1;
    else {
        int rL = find(root->left, elem);

        if (rL)
            return rL;
        else
            return (find(root->right, elem));
    }
}

// least common ancestor  (lca)

Node *lca(Node *root, int v1, int v2) {

    if (root == NULL)
        return NULL;
    // considering root to be the ancestor

    else {

        int v1L = find(root->left, v1);
        int v2R = find(root->right, v2);

        int v1R = find(root->right, v1);
        int v2L = find(root->left, v2);

        if ((v1L && v2R) || (v1R && v2L)) {
            return root;
        }

        Node *lF = lca(root->left, v1, v2);

        if (lF)
            return lF;
        else
            return (lca(root->right, v1, v2));
    }
}

int main() {
    Node *root = NULL;

    root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);

    preorder(root);

    cout << endl;

    cout << lca(root, 1, 3)->value << endl;
}
