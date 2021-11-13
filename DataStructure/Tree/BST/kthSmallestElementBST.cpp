
int find(TreeNode* root, int &k) {

    if (!root)
        return -1; // We do an inorder traversal here.
    int k1 = find(root->left, k);
    if (k == 0)
        return k1; // left subtree has k or more elements.
    k--;
    if (k == 0)
        return root->val; // root is the kth element.
    return find(root->right, k); // answer lies in the right node. }
}

int kthsmallest(TreeNode* root, int k) {
    return find(root, k); // Call another function to pass k by reference.
}

