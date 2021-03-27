/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool find(TreeNode* root,int elem){
    if(!root)
        return false;
    if(root->val == elem)
        return true;
    return find(root->left,elem) || find(root->right,elem);
}

TreeNode* solve(TreeNode* root,int a,int b){
    if(!root)
        return NULL;
    
    if(root->val == a || root->val == b)
        return root;
    
    TreeNode* left = solve(root->left,a,b);
    TreeNode* right = solve(root->right,a,b);
    
    if(left && right)
        return root;
    return left?left:right;
}


 
int Solution::lca(TreeNode* A, int B, int C) {
    
    if(!find(A,B) || !find(A,C))
        return -1;
    
    TreeNode* rt =  solve(A,B,C);
    if(!rt)
        return -1;
    return rt->val;
}
