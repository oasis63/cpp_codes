// delete node from a tree

#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *newNode(int value) {
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node *insert(Node *root, int data) {
    if (root == NULL)
        root = newNode(data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    return root;
}

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void lvl(Node *root) {

    queue<Node *> q;

    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

// find max in bst

Node *findMax(Node *root) {

    if (root == NULL)
        return root;
    else if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
}

Node *deleteNode(Node *root, int data) {

    if (root == NULL) {
        cout << "Element is not present" << endl;
        return root;
    }

    Node *mxLeftNode = findMax(root->left);

    root->data = mxLeftNode->data;

    queue<Node *> q;

    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp->right == mxLeftNode) {
            delete temp->right;
            temp->right = NULL;
            cout << "\n" << data << " Deleted Successfully" << endl;
            return root;
        } else if (temp->left == mxLeftNode) {
            delete temp->left;
            temp->left = NULL;
            cout << "\n" << data << " Deleted Successfully" << endl;
            return root;
        }

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

bool checkBST(Node *root) {

    if (root == NULL)
        return true;

    if (root->left != NULL && root->data < root->left->data)
        return false;

    if (root->right != NULL && root->data > root->right->data)
        return false;

    if (!checkBST(root->left) || !checkBST(root->right))
        return false;
    return true;
}

int maxNodeValue(Node *root) {
    if (root == NULL)
        return INT_MIN;
    return max(
        {root->val, maxNodeValue(root->left), maxNodeValue(root->right)});
}

int minNodeValue(Node *root) {
    if (root == NULL)
        return INT_MAX;
    return min({root->val, minNodeValue(root->left), minNodeValue(root->left)});
}

bool isValidBST(Node *root) {
    // base case
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left != NULL && root->val <= maxNodeValue(root->left))
        return false;
    if (root->right != NULL && root->val >= minNodeValue(root->right))
        return false;
    return isValidBST(root->left) && isValidBST(root->right);
}

Node *kthSmallest(Node *root, int k, int count) {
    if (!root)
        return NULL;

    Node *left = kthSmallest(root->left, k, count);

    if (left)
        return left;

    count++;
    if (count == k)
        return root;

    return kthSmallest(root->right, k, count);
}

void rangePrinter(Node *root, int k1, int k2) {
    if (root) {
        rangePrinter(root->left, k1, k2);
        if (root->data >= k1 && root->data <= k2)
            cout << root->data << " ";
        rangePrinter(root->right, k1, k2);
    }
}

int main() {
    Node *root = NULL;

    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 0);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 11);

    checkBST(root) == 1 ? cout << "BST" << endl : cout << "Not a BST" << endl;

    lvl(root);

    cout << endl;

    inorder(root);

    cout << "\n The 3rd smallest number from the tree is " << endl;

    int k = 2;
    int count = 0;

    cout << kthSmallest(root, k, count)->data << endl;

    cout << "\n Numbers betweeen 0  to 11 " << endl;

    rangePrinter(root, 2, 4);
}
