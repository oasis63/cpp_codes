 bool identicalTree(TreeNode* A,TreeNode* B){
     
     if(A==NULL && B==NULL)
        return true;
    else if(A==NULL || B==NULL)
        return false;
     
     return (A->val == B->val) &&identicalTree(A->right,B->left)&&identicalTree(A->left,B->right);
 }
 
int Solution::isSymmetric(TreeNode* A) {
    return identicalTree(A->right,A->left);
}
