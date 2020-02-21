int isIdenticalTrees(TreeNode* A, TreeNode* B) {
    
    if(A==NULL && B==NULL)
        return 1;
    else if(A==NULL  || B==NULL)
        return 0;
    
    return (A->val==B->val  && isIdenticalTrees(A->left,B->left) && isIdenticalTrees(A->right,B->right));

}