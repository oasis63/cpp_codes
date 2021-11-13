int isSameTree(TreeNode* A, TreeNode* B) {
    
    if(A==NULL && B==NULL)
        return 1;
    else if(A==NULL  || B==NULL)
        return 0;
    
    return (A->val==B->val  && isSameTree(A->left,B->left) && isSameTree(A->right,B->right));

}